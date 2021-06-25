#include<bits/stdc++.h>
using namespace std;

void pairStar(char input[]) {
    // Write your code here
    int size = 0;
    for(int i = 0; input[i] != '\0'; i++){
            size++;
    }
    if(*input == '\0')
        return;
    
    else if(input[0] == input [1]){
        for(int i = size+1; i >+ 0; i--){
            input[i] = input[i-1];
        }
        size += 1;
        input[1] = '*';
    }

    pairStar(input+1);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}