#define _USE_MATH_DEFINES
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

Node* ReverseLinkedList(Node* start){
	// http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/
	if (start == nullptr || start->next == NULL){
		return start;
	}

	Node *prev = NULL, *forward = start->next;
	while (start->next != NULL){
		start->next = prev;
		prev = start;
		start = forward;
		forward = start->next;
	}

	start->next = prev;

	return start;
}