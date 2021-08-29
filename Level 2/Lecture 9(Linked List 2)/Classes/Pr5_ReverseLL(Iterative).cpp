#include<bits/stdc++.h>
using namespace std;

//Part of the given code
class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


//Reversing a Linked List iteratively
Node *reverseLinkedList(Node *head) {
    // Write your code here
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;

	while(current != NULL) {
		next = current -> next;
		current -> next = prev;

		prev = current;
		current = next;
	}

	return prev;
}


//Part of the given code
Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}