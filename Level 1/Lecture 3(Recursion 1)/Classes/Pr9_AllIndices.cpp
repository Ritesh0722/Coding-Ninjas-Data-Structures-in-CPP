#include<bits/stdc++.h>
using namespace std;


int allIndices(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(size==0)
      return 0;
    int smallAllIndexes=allIndices(input, size-1, x , output );
    if(input[size-1]==x)
    {
        output[smallAllIndexes]=size-1;
        return smallAllIndexes+1; 
    }
    return smallAllIndexes;
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
    
    int *output = new int[n];
    
    int size = allIndices(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}