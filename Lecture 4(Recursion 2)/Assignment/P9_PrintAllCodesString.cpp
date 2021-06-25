/***
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S.
Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw

***/

#include<bits/stdc++.h>
using namespace std;

void printAllPossibleCodesHelper(string input, string output) {
	if(input.empty()) {
		cout<<output<<endl;
		return;
	}

	string newOutput = "";

	newOutput = output + char(stoi(input.substr(0, 2)) + 96);
	output = output + char(stoi(input.substr(0, 1)) + 96);

	printAllPossibleCodesHelper(input.substr(1), output);
	
    if(input.size() > 1 && stoi(input.substr(0, 2)) <= 26)
		printAllPossibleCodesHelper(input.substr(2), newOutput);

	
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = "";
	printAllPossibleCodesHelper(input, output);
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}