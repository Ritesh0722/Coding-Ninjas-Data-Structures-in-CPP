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


//Insert node using recursion
Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(head == NULL)
        return head;
    
    if(i == 0){
        Node *temp = new Node(data);
    	temp -> next = head;
        head = temp;
    	return head;
    }
    
    if(head != NULL){
    	Node *smallHead = insertNode(head -> next, i - 1, data);
    	head -> next = smallHead;
    }
    return head;
}


//Part of the given code
Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}