#include<bits/stdc++.h>
// #include<stack>              //headerfile for inbuilt stack
using namespace std;

int main(){
    stack<int> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);


	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	cout << s.size() << endl;

	cout << s.empty() << endl;
}