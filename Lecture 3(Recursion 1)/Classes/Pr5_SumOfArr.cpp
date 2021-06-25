#include<bits/stdc++.h>
using namespace std;

int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(n == 1 || n == 0){
        return input[0];
    }
    int smallSum = sum(input+1, n-1);
    // cout<<smallSum<<" ";
    return input[0] + smallSum;
}


int main(){
    int arr[4] = {2,4,5,6};
    int n = 4;

    cout<<sum(arr, n);
}