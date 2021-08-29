#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n == 1 || n == 0)
        return n;
    
    int a = fibo(n-1);
    int b = fibo(n-2);

    // cout<< a+b<<" ";
    return a+b;
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n);   
}