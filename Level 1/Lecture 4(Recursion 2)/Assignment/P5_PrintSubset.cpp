/***
 Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12  
 ***/

#include<bits/stdc++.h>
using namespace std;

void printSubsetsOfArrayHelper(int input[], int size, int output[], int nSize){
    if(size == 0){
        for(int i = 0; i < nSize; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int newOutput[30];
    printSubsetsOfArrayHelper(input + 1, size-1, output, nSize);
    for(int i = 0; i < nSize; i++){
        newOutput[i] = output[i];
    }
    newOutput[nSize] = input[0];
    printSubsetsOfArrayHelper(input + 1, size-1, newOutput, nSize + 1);

}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[20];
    int nSize = 0;
    printSubsetsOfArrayHelper(input, size, output, nSize);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}