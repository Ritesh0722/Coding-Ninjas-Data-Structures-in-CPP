/***
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba

***/

#include<bits/stdc++.h>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	if(input.empty()) {
		output[0] = "";
		return 1;
	}

	int smallOutputSize = returnPermutations(input.substr(1), output);

	string temp;
    for(int i = 0; i < smallOutputSize; i++)
    {
        temp = output[i];
        for(int j = 0; j <= temp.size(); j++)
        {
            temp.insert(j, 1, input[0]);
            output[j * smallOutputSize + i] = temp;
            temp.erase(j, 1);
        }
    }

	return smallOutputSize * output[0].size();
}

int main(){
    string input;
    cin >> input;
    string output[1000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 1000; i++){
        cout << output[i] << endl;
    }
    return 0;
}