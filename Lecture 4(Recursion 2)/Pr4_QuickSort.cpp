#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int input[], int start, int end){
    if(start == end)
        return 0;
    
    int i = start - 1;
    int pivot = input[end];

    for(int j = start; j <= end - 1; j++){
        if(input[j] < pivot){
            i++;
            swap(&input[i], &input[j]);
        }
    }

    swap(&input[i+1], &input[end]);

    return (i + 1);
}

void helper(int input[], int start, int end){
    if(start >= end)
        return;

    int x = partition(input, start, end);
    helper(input, start, x-1);
    helper(input, x+1, end);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    helper(input, 0, size - 1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;
}