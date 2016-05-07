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
	Node* next = NULL;
};

Node* GetNode(int data){
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
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

// http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/
Node* ReverseLinkedList(Node* start){
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

// http://www.geeksforgeeks.org/sum-of-two-linked-lists/
Node* SumLinkedList(Node* num1, Node* num2){
	if (num1 == NULL || num2 == NULL){
		throw "InvalidInput";
	}

	Node* num1Rev = ReverseLinkedList(num1);
	Node* num2Rev = ReverseLinkedList(num2);
	Node* final = NULL, *current = final;
	int carry = 0;
	while (num1Rev != NULL && num2Rev != NULL){
		int curr = num1Rev->data + num2Rev->data + carry;
		int rem = curr % 10;
		carry = curr / 10;
		current = GetNode(rem);

		current->next = final;
		final = current;
		num1Rev = num1Rev->next;
		num2Rev = num2Rev->next;
	}
	if (num1Rev == NULL){
		while (num2Rev != NULL){
			int curr = num2Rev->data + carry;
			int rem = curr % 10;
			carry = curr / 10;

			current = GetNode(rem);
			current->next = final;
			final = current;
			current = current->next;
			num2Rev = num2Rev->next;
		}
	}
	else if (num2Rev == NULL){
		while (num1Rev != NULL){
			int curr = num1Rev->data + carry;
			int rem = curr % 10;
			carry = curr / 10;

			current = GetNode(rem);
			current->next = final;
			final = current;
			current = current->next;
			num1Rev = num1Rev->next;
		}
	}

	if (carry == 1){
		current = GetNode(1);
		current->next = final;
		final = current;
	}

	return final;
}

Node* GetLinkedList(int* arr, int size){
	Node* head = NULL, *curr;
	for (int i = 0; i < size; i++){
		curr = GetNode(arr[i]);
		curr->next = head;
		head = curr;
	}

	return head;
}