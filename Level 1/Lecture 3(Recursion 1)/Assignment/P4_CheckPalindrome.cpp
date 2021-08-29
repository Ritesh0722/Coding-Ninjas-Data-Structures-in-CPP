#include<bits/stdc++.h>
using namespace std;

bool helper(char input[], int start, int end, int size){
    if(size == 1 || size == 0)
        return true;
    if(input[start] != input[end])
        return false;
    bool smallCheckPal;
    // cout<<size<<endl;
    if(end>=start){smallCheckPal = helper(input, start+1, end-1, size-2);}

    return smallCheckPal;
}


bool checkPalindrome(char input[]) {
    // Write your code here
    int size = 0;
    for(int i = 0; input[i] != '\0'; i++){   
        size++;
    }

    bool res = helper(input, 0, size-1, size);

    return res;
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}