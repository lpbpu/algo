#include <stdio.h>
#include <stdlib.h>

typedef struct node_stru{
	int val;
	struct node_stru *next;
}mynode;



mynode *init_node(){
	mynode *dummy=NULL;
	mynode *newnode=NULL;
	int vallist[]={3,3,2,1,1};
	int i;

	dummy=(mynode *)malloc(sizeof(mynode));
	dummy->next=NULL;

	for (i=0;i<sizeof(vallist)/sizeof(vallist[0]);i++){
		newnode=(mynode *)malloc(sizeof(mynode));
		newnode->val=vallist[i];
		newnode->next=dummy->next;
		dummy->next=newnode;	
	}


	return dummy->next;
	

}


void print_node(mynode *head)
{
	while(head!=NULL){
		printf("%d->",head->val);
		head=head->next;
	}
	printf("NULL\n");
}

void removedup(mynode *head)
{
	mynode *prev;
	prev=head;
	head=head->next;

	while(head!=NULL){
		if (head->val==prev->val){
			prev->next=head->next;
			free(head);
			head=prev->next;	
		}else{
			head=head->next;
			prev=prev->next;
		}
	}
}


int main()
{
	mynode *head=NULL;
	
	head=init_node();

	print_node(head);


	removedup(head);

	print_node(head);

	return 0;

	
}
