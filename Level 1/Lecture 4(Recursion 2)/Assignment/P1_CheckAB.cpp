#include<bits/stdc++.h>
using namespace std;

bool checkABHelper(char input[]) {
	// Write your code here
	if(input[0] == '\0'){
        return false;
    }

    else if(input[0] == 'a'){
        if(input[1] != '\0')
    	    return checkABHelper(input + 1);
        else
            return true;
    }

    else {
        if(input[0] == 'b' && input[1] == 'b'){
            if(input[2] == '\0')
                return true;
            else
            	return checkABHelper(input+2);
        }
        else
            return false;
    }
}

bool checkAB(char input[]) {
	// Write your code here
	if(input[0] == '\0' || input[0] != 'a')
        return false;
    else
        checkABHelper(input);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}