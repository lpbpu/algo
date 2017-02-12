#include <stdio.h>
#include <stdlib.h>

typedef struct node_stru{
	int val;
	struct node_stru *next;
}mynode;



mynode *init_node(){
	mynode *dummy=NULL;
	mynode *newnode=NULL;
	int vallist[]={3,2,2,2,1,1,1};
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

mynode *removedup(mynode *dummy)
{
	mynode *node=dummy;

	while (node->next != NULL && node->next->next != NULL) {
            if (node->next->val == node->next->next->val) {
                int val = node->next->val;
                while (node->next != NULL && val == node->next->val) {
                    mynode *temp = node->next;
                    node->next = node->next->next;
                    free(temp);
                }
            } else {
                node = node->next;
            }
        }


	return dummy->next;


}


int main()
{
	mynode *dummy_head=NULL;
	mynode *new_head=NULL;
	
	dummy_head=init_node();

	print_dummy_node(dummy_head);


	new_head=removedup(dummy_head);

	print_dummy_node(new_head);

	return 0;

	
}
