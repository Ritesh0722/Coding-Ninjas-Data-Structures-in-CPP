#include<bits/stdc++.h>
using namespace std;

void printSubsetSumToKHelper(int input[], int size, int k, int output[], int nSize) {
    if(size == 0) {
        if(k == 0) {
            for(int i = nSize - 1; i >= 0; i--) {
                cout<<output[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else 
            return;
    }

    int newOutput[30];

    printSubsetSumToKHelper(input + 1, size - 1, k, output, nSize);
    for(int i = nSize - 1; i >= 0; i--) {
        newOutput[i + 1] = output[i];
    }
    newOutput[0] = input[0];
    printSubsetSumToKHelper(input + 1, size - 1, k - input[0], newOutput, nSize + 1);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[50];
    int nSize = 0;
    printSubsetSumToKHelper(input, size, k, output, nSize);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}