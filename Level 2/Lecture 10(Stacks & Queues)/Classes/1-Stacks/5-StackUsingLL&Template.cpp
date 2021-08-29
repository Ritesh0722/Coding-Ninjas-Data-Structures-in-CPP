#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Node {
public:
	int data;
	Node<T> *next;
	Node(T data)
	{
		this->data = data;
		this->next = NULL;
	}
};

template<typename T>
class StackUsingLL {
    int sizeOfStack;
    public:
    Node<T> *head;
    StackUsingLL() {
        sizeOfStack = 0;
        head = NULL;
    }
    
    int getSize() {
        return sizeOfStack;
    }
 
    bool isEmpty() {
		return head == NULL;
	}

    void push(T element) {
        Node<T> *newNode = new Node<T>(element);

        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        sizeOfStack++;
    }

    T pop() {
        if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;	
		}
        int temp = head->data;
        head = head->next;
        sizeOfStack--;
        return temp;        
    }

    T top() {
        if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;	
		}
        return head->data;
    }
};

int main() {
    StackUsingLL<int> s;
    s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);
	s.push(106);
	s.push(107);
	s.push(108);
	s.push(109);
	s.push(110);
	s.push(111);


	cout << s.top() << endl;            //top

	cout << s.pop() << endl;    //pop
	cout << s.pop() << endl;    //pop
	
    cout << s.top() << endl;            //top

	cout << s.pop() << endl;    //pop

	cout << s.getSize() << endl;

	cout << s.isEmpty() << endl;
}