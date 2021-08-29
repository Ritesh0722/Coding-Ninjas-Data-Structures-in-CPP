#include<bits/stdc++.h>
using namespace std;

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	if(size == 0)
        return -1;
    
    // int count = 0;
    if(input[size-1] == x)
        return size-1;
    // count++;
    int smallLastIndex = lastIndex(input, size-1, x);

    return ((smallLastIndex == -1) ? smallLastIndex:(smallLastIndex+1));
    // return smallLastIndex;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}