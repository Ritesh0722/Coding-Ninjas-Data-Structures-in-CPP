/***
Swap two Nodes of LL

You have been given a singly linked list of integers along with two integers, 'i' and 'j', 
Swap the nodes that are present at the 'i-th' and 'j-th' positions.

Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M
Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 

Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
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


//Function to swap two node(not only the data)
Node* swapNodes(Node *head,int i,int j)
{
    Node *current=head;
	Node *prev, *previ, *currenti, *prevj, *currentj;
    prev = previ = currenti = prevj = currentj = NULL;
    int count = 0;

    while(current != NULL)
    {
        if(count == i)
        {
            previ = prev;
            currenti = current;
        }
        else if(count == j)
        {
            prevj = prev;
            currentj = current;
        }
        prev = current;
        current = current -> next;
        count++;
    }
    if(currenti == NULL || currentj == NULL)
        return head;

    if(previ == NULL)
        head = currentj;
    else
        previ -> next = currentj;

    if(prevj == NULL)
        head = currenti;
    else
        prevj -> next = currenti;

    current = currenti -> next;
    currenti -> next = currentj -> next;
    currentj -> next = current;

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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}