// C++ program to delete all odd
// node from a Circular singly linked list

#include <bits/stdc++.h>
using namespace std;

// Structure for a node
struct Node {
	int data;
	struct Node* next;
};

// Function to insert a node at the beginning
// of a Circular linked list
void push(struct Node** head_ref, int data)
{
	struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;

	// If linked list is not NULL then
	// set the next of last node
	if (*head_ref != NULL) {
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		// For the first node
		ptr1->next = ptr1;

	*head_ref = ptr1;
}

// Delete the node if it is odd
void deleteNode(Node* head_ref, Node* del)
{
	struct Node* temp = head_ref;
	// If node to be deleted is head node

	if (head_ref == del)
		head_ref = del->next;

	// Traverse list till not found
	// delete node
	while (temp->next != del) {
		temp = temp->next;
	}

	// Copy address of node
	temp->next = del->next;

	// Finally, free the memory occupied by del
	free(del);
	return;
}

// Function to delete all odd nodes
// from the singly circular linked list
void deleteoddNodes(Node* head)
{
	struct Node* ptr = head;

	struct Node* next;

	// Traverse list till the end
	// if the node is odd then delete it
	do {
	// point to next node
		next = ptr->next;
		// if node is odd
		if ((ptr->data % 2) == 1)
			deleteNode(head, ptr);
		// get the next element
		ptr = next;
	} while (ptr != head);
}

// Function to print nodes
void printList(struct Node* head)
{
	struct Node* temp = head;
	if (head != NULL) {
		do {
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);
	}
}

// Driver code
int main()
{
	// Initialize lists as empty
	struct Node* head = NULL;

	// Created linked list will be 56->61->57->11->12->2
	push(&head, 2);
	push(&head, 12);
	push(&head, 11);
	push(&head, 57);
	push(&head, 61);
	push(&head, 56);

	cout << "\nList after deletion : ";
	deleteoddNodes(head);
	printList(head);

	return 0;
}
