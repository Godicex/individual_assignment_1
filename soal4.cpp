#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int angka;
	Node* next;
};

void penghapus(Node* head)
{
	Node* curr = head;
	Node* next2; 

	if (curr == NULL){
	  return; 
    }
	while (curr->next != NULL) {
	if (curr->angka == curr->next->angka) {	
        next2 = curr->next->next;
		free(curr->next);
		curr->next = next2; 
	}
	else{
		curr = curr->next; 
	}
	}
}

void push(Node** head2, int new_data){
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->angka = new_data;
	new_node->next = (*head2);	 
	(*head2) = new_node;
}

void printList (Node *node)
{
	while (node!=NULL){
	printf("%d -> ", node->angka);
	node = node->next;
	}
    puts("NULL");
} 

int main(){
	Node* head = NULL;
	push(&head, 80);
	push(&head, 21); 
	push(&head, 21);
	push(&head, 95);
	push(&head, 95);
    push(&head, 88);
    push(&head, 23);
    push(&head, 22);								 
	printf("Linked List Before: ");
	printList(head);
	penghapus(head); 
	printf("Linked List After:  ");		 
	printList(head);		 
	return 0;
}