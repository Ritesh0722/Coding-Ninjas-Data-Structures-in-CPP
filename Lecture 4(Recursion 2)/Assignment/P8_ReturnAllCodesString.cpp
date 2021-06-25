/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S.
Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

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
*/

#include<bits/stdc++.h>
using namespace std;

int getCodes(string input, string output[100]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
   if(input == "") {
        output[0] = "";
        return 1;
    }

    int smallOutputSize1 = getCodes(input.substr(1), output);
    int smallOutputSize2 = 0;

    if(input.size() > 1 && stoi(input.substr(0, 2)) <= 26)
        smallOutputSize2 = getCodes(input.substr(2), output + smallOutputSize1);

    int smallOutputSize = smallOutputSize1 + smallOutputSize2;

    for(int i = 0; i < smallOutputSize1; i++)
        output[i] = char(stoi(input.substr(0, 1)) + 96) + output[i];

    for(int j = smallOutputSize1; j < smallOutputSize; j++)
        output[j] = char(stoi(input.substr(0, 2)) + 96) + output[j];
    
    return smallOutputSize;    
}

int main(){
    string input;
    cin >> input;

    string output[100];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 100; i++)
        cout << output[i] << endl;
    return 0;
}