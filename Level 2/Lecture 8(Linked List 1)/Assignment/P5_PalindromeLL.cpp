/***
Palindrome LinkedList

You have been given a head to a singly linked list of integers. Write a function check to whether
the list given is a 'Palindrome' or not.

 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec
Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true

Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
***/

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

//function to rever a Linked List (used here for reversing the second half of the LL)
Node* reverseList(Node *head){  
    Node *temp = head;  
    Node *prevNode = NULL;
	Node *nextNode = NULL;
       
    while(temp != NULL){  
        nextNode = temp->next;  
        temp->next = prevNode;  
        prevNode = temp;  
        temp = nextNode;  
    }  
    return prevNode;  
}

//check if the Linked List is Palindrome or not
bool isPalindrome(Node *head)
{
    //Write your code here
	if(head == NULL) {
		return true;
	}

	int count = 0;
	Node *temp = head;  
    bool flag = true;  

	while(temp != NULL) {
		temp = temp -> next;
		count++;
	}

	temp = head;
      
    //Store the mid position of the list
    int mid = (count % 2 == 0)? (count / 2) : ((count + 1) / 2);  
      
    //Finds the middle node in given singly linked list
    for(int i = 1; i < mid; i++){  
        temp = temp -> next;  
    }  
        
    Node *revHead = reverseList(temp -> next);		//Reverse the list after middle node to end (second half)
	
	temp = head;
   
    //Compare nodes of first half and second half of list  
    while(temp != NULL && revHead != NULL){  
        if(temp -> data != revHead -> data){  
            flag = false;  
            break;  
        }  
        temp = temp -> next;  
        revHead = revHead -> next;  
    }
	return flag;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}