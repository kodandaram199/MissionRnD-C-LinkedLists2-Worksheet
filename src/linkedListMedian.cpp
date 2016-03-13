/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.
INPUTS: A sorted linked list.
OUTPUT: Return median of the linked list elements.
ERROR CASES: Return -1 for error cases.
NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	if (head == 0)
		return -1;

	struct node *ptr1,*ptr2;
	ptr1 = ptr2 = head;
	while (ptr1 != NULL && ptr1->next != NULL){
		if (ptr1->next->next == NULL){
			return (ptr2->num + ptr2->next->num) / 2;
		}
		ptr2 = ptr2->next;
		ptr1 = ptr1->next->next;
		}
	return ptr2->num;
}