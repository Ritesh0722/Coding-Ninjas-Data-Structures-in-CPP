#include<bits/stdc++.h>
using namespace std;

int helper(char input[], int size){
    int res = 0;
    if(size == 0)
        return 0;
    
    res = (int)input[size-1] - '0';
    int smallChar = helper(input, size-1);
    return res + (smallChar*10);
}

int stringToNumber(char input[]) {
    // Write your code here
    int size = 0;
    for(int i = 0; input[i] != '\0'; i++)
        size++;
    int result = helper(input, size);
    return result;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}