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

//Time: O(N^2)   because of using loop to traverse through the LL to get to the last node
Node* takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;

    while (data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
        }
        else {
            Node *temp = head;
            while(temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }

        cin >> data;
    }
    return head;
}

//Time: O(N) using tail pointer to point at the last node
Node* takeInput_better() {
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

//Print the linked list
void print(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    //Using head it prints the LL for the second time
    // while(head != NULL) {
    //     cout << head -> data << " ";
    //     head = head -> next;
    // }
}

int main(){
    //Statically crated nodes
    /*
    Node n1(10);
    Node n2(20);
    Node n3(30);

    Node *head = &n1;

    n1.next = &n2;
    n2.next = &n3;

    print(head);
    */

    //Dynamically created nodes
    /*
    Node *n4 = new Node(40);
    Node *head = n4;

    Node *n5 = new Node(50);
    n4 -> next = n5;

    print(head);

    delete n4, n5;
    */
    
    Node *head = takeInput();
    print(head);
}