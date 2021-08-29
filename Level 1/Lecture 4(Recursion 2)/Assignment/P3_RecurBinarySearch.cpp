#include<bits/stdc++.h>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched
int binarySearchHelper(int input[], int start, int end, int element){
    if(start > end)
        return -1;
    
    int m = (start + end) / 2;
        
    if(input[m] == element)
        return m;
    else if(input[m] < element)
        return binarySearchHelper(input, m + 1, end, element);
    else if(input[m] > element)
        return binarySearchHelper(input, start, m - 1, element);  
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    if(element < input[0] || element > input[size - 1])
        return -1;
    
    return binarySearchHelper(input, 0, size - 1, element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}