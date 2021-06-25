#include<bits/stdc++.h>
using namespace std;

int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	if(size == 0)
        return -1;
    
    // int count = 0;
    if(input[0] == x)
        return 0;
    // count++;
    int smallFirstIndex = firstIndex(input+1, size-1, x);

    return ((smallFirstIndex == -1) ? smallFirstIndex:(smallFirstIndex+1));
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
    
    cout << firstIndex(input, n, x) << endl;

}
