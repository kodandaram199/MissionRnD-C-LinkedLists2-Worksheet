/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5
INPUTS: A linked list and Value of K.
OUTPUT: Insert a new node at every Kth node with value K.
ERROR CASES: Return NULL for error cases.
NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	if (head == NULL)
		return NULL;

	struct node *temp, *prev;
	temp = head;
	int count = K;
	if (K < 1)
		return NULL;
	while (temp != NULL){
		count--;
		prev = temp;
		temp = temp->next;
		if (count == 0){
			struct node* nodeAtK = (struct node*) malloc(sizeof(struct node));
			nodeAtK->num = K;
			prev->next = nodeAtK;
			nodeAtK->next = temp;
			count = K;
		}
	}
	return head;
}