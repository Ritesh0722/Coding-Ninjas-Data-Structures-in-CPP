#include<bits/stdc++.h>
using namespace std;

void removeX(char input[]) {
    // Write your code here
    if(input[0] == '\0')
        return;

    else if(*input == 'x'){
        for(int i = 0; input[i] != '\0'; i++){
            input[i] = input[i+1];
        }
        // cout<<input<<endl;
        removeX(input);
    }
    removeX(input+1);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}