#include<bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    if(*input == '\0')
        return;
    
    else if(input[0] == input [1]){
        for(int i = 0; input[i] != '\0'; i++){
            input[i] = input[i+1];
        }
        // cout<<input<<endl;
        removeConsecutiveDuplicates(input);
    }
        removeConsecutiveDuplicates(input+1);
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}