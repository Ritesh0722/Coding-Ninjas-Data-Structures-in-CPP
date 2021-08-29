#include<bits/stdc++.h>
using namespace std;

//Structure of a node of a linked list using class
class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

//Time: O(N) using tail pointer to point at the last node
Node* takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = tail -> next;            //or      tail = newNode;
        }

        cin >> data;
    }
    return head;
}

//insert a node at i-th position
Node* insertNode(Node *head, int data, int i) {
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;

    if(i == 0) {
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while(count < i - 1 && temp != NULL) {
        temp = temp -> next;
        count++;
    }
    
    if(temp != NULL) {
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return head;
}

//Print the linked list
void print(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){  
    Node *head = takeInput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertNode(head, data, i);
    print(head);
}