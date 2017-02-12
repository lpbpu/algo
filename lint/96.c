#include <stdio.h>
#include <stdlib.h>

typedef struct node_stru{
	int val;
	struct node_stru *next;
}mynode;



mynode *init_node(){
	mynode *dummy=NULL;
	mynode *newnode=NULL;
	int vallist[]={2,5,2,3,4,1};
	int i;

	dummy=(mynode *)malloc(sizeof(mynode));
	dummy->next=NULL;

	for (i=0;i<sizeof(vallist)/sizeof(vallist[0]);i++){
		newnode=(mynode *)malloc(sizeof(mynode));
		newnode->val=vallist[i];
		newnode->next=dummy->next;
		dummy->next=newnode;	
	}


	return dummy;
	

}


void print_dummy_node(mynode *dummy)
{
	mynode *head=dummy->next;
	while(head!=NULL){
		printf("%d->",head->val);
		head=head->next;
	}
	printf("NULL\n");
}


mynode *partition(mynode *head,int x){
	mynode *left,*lefthead;
	mynode *right,*righthead;

	left=(mynode *)malloc(sizeof(mynode));
	right=(mynode *)malloc(sizeof(mynode));

	lefthead=left;
	righthead=right;

	head=head->next;


	while(head!=NULL){
		if (head->val<x) {
			left->next=head;
			left=head;

		}else{
			right->next=head;
			right=head;
		}
		head=head->next;

	}

	right->next=NULL;
	left->next=righthead->next;

	return lefthead;

	


}


int main()
{
	mynode *dummy_head=NULL;
	mynode *new_head=NULL;
	
	dummy_head=init_node();

	print_dummy_node(dummy_head);


	new_head=partition(dummy_head,3);

	print_dummy_node(new_head);

	return 0;

	
}
