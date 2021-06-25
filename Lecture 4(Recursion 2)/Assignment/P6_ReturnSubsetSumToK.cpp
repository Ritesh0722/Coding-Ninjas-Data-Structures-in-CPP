/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include<bits/stdc++.h>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n == 0){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }

    int smallSubsetSize1 = subsetSumToK(input + 1, n - 1, output, k);
    int smallSubsetSize2 = subsetSumToK(input + 1, n - 1, output + smallSubsetSize1, k - input[0]);

    int smallOutputSize = smallSubsetSize1 + smallSubsetSize2;
    for(int i = smallSubsetSize1; i < smallOutputSize; i++) {
        for(int j = output[i][0]; j > 0; j--) {
            output[i][j + 1] = output[i][j];
        }
        output[i][1] = input[0];
        output[i][0]++;
    }
    return smallOutputSize;
}

int main() {
  int input[20],length, output[100][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}