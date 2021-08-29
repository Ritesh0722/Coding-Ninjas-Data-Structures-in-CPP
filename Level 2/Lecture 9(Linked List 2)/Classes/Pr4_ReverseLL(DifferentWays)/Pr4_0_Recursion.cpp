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


//Reversing a Linked List using recursion
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
	if(head == NULL || head -> next == NULL)
		return head;

	Node* smallRev = reverseLinkedListRec(head -> next);
	
	Node* temp = smallRev;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = head;
	head -> next = NULL;

	return smallRev;
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

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}