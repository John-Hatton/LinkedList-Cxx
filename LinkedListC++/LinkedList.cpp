#include "stdc.h";

using namespace std;

class Node
{
	// Access Modifier
	public:

		int data;
		Node *next;

};


void push(Node** headReference, int newData)
{
	// allocate a new node in the heap
	Node* newNode = new Node();

	// give node some data
	newNode->data = newData;

	// make next node point to head reference
	newNode->next = (*headReference);

	// move head to point to new node
	(*headReference) = newNode;

}


void insertAfter(Node* previousNode, int newData)
{
	if (previousNode == NULL)
	{
		cout << "This LinkedList is Empty...";
		return;
	}

	// Allocate a new node in the heap
	Node* newNode = new Node();


	// Give node some data
	newNode->data = newData;

	// Set new node's next pointer to 
	//  previous node's next pointer.
	newNode->next = previousNode->next;

	// move previous node's next
	//  to new_node

	previousNode->next = newNode;

}

void append(Node** headReference, int newData)
{
	// Allocate a new node in the heap
	Node* newNode = new Node();

	Node* last = *headReference; 


	// Give new node some data
	newNode->data = newData;

	
	newNode->next = NULL;

	if (*headReference == NULL)
	{
		*headReference = newNode;
		return;
	}

	// traverse till the last node
	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = newNode;
	return;

}

void printList(Node* node)
{
	while (node != NULL)
	{
		cout << " " << node->data;
		node = node->next;
	}

}

// Driver Code
int main()
{
	cout << "Hello World!\n";


	Node* head = NULL;

	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	insertAfter(head->next->next, 5);
	cout << "Your new LinkedList Reads: ";
	printList(head);

	cin.get();







}