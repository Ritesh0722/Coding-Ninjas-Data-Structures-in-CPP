#include<bits/stdc++.h>
using namespace std;

//Part of the given code
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


//For merging the two sorted Linked Lists
Node* sortedMerge(Node* a, Node* b) {
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    Node* result = NULL;
 
    // pick either `a` or `b`, and recur
    if (a -> data <= b -> data)
    {
        result = a;
        result -> next = sortedMerge(a -> next, b);
    }
    else {
        result = b;
        result -> next = sortedMerge(a, b -> next);
    }
 
    return result;
}
 
/*
    Split the given list's nodes into front and back halves
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    It uses the fast/slow pointer strategy
*/
void frontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    // if the length is less than 2, handle it separately
    if (source == NULL || source -> next == NULL) {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    Node* slow = source;
    Node* fast = source->next;
 
    // advance `fast` two nodes, and advance `slow` one node
    while (fast != NULL) {
        fast = fast -> next;
        if (fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
 
    // `slow` is before the midpoint in the list, so split it in two
    // at that point.
    *frontRef = source;
    *backRef = slow -> next;
    slow -> next = NULL;
}

//MergeSort
Node *mergeSort(Node *head)
{
	//Write your code here
	if (head == NULL || head -> next == NULL) {
        return head;
    }
 
    Node* a;
    Node* b;
 
    // split `head` into `a` and `b` sublists
    frontBackSplit(head, &a, &b);
 
    // recursively sort the sublists
    a = mergeSort(a);
    b = mergeSort(b);
 
    // answer = merge the two sorted lists
    head = sortedMerge(a, b);

	return head;
}


//Part of the given code
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}