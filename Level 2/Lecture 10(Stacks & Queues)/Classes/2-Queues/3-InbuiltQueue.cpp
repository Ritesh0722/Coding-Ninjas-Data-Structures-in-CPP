#include<bits/stdc++.h>
// #include<queue>              //headerfile for inbuilt queue
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;

    cout<<q.size()<<endl;

    q.push(40);
    q.push(50);
    q.push(60);

    cout<<q.size()<<endl;

    q.push(70);
    
    cout<<q.size()<<endl;

    cout<<q.empty()<<endl;
}