#include<bits/stdc++.h>
using namespace std;

void helper(char input[], int size){
    if(size <= 1){
        return;
    }

    if(input[0] == 'p' && input[1] == 'i'){
        for(int i = size+2; i >= 0; i--){
            input[i] = input[i-2];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        size += 2;
        helper(input+2, size-2);
    }

    helper(input+1, size-1);
}

void replacePi(char input[]) {
	// Write your code here
    int size = 0;
    for(int i = 0; input[i] != '\0'; i++){   
        size++;
    }

   helper(input, size);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
