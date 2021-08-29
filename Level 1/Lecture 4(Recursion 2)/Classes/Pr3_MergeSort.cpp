#include<bits/stdc++.h>
using namespace std;

void merge(int input[] , int start, int mid, int end){
	int p = start ,q = mid+1;

	int Arr[end-start+1] , k=0;

    for(int i = start ;i <= end ;i++) {
        if(p > mid)
            Arr[k++] = input[q++] ;

        else if (q > end)
            Arr[k++] = input[p++];

        else if(input[p] < input[q])
            Arr[k++] = input[p++];

        else
            Arr[k++] = input[q++];
    }
    for (int p=0 ; p< k ;p ++) {
        input[start++] = Arr[p] ;                          
    }
}

void helper(int input[ ] , int start , int end )
{
  if( start < end ) {
    int mid = (start + end ) / 2 ;
    helper (input, start , mid ) ;             
    helper (input, mid+1 , end ) ;              

    merge(input,start , mid , end );   
  }                    
}

void mergeSort(int input[], int size){
	// Write your code here
    helper(input, 0, size-1);
}

int main() {
    int length;
    cin >> length;
    int* input = new int[length];
    for(int i=0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for(int i = 0; i < length; i++) {
        cout << input[i] << " ";
    }
}