#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int result = 1;
    cout<<n<<endl;
    if(n>1)
        result = n * factorial(n-1);
    return result;
}

int main(){
    int n;
    cin>> n;
    int output = factorial(n);
    cout<<output;
}