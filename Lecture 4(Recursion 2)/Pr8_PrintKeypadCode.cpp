#include<bits/stdc++.h>
using namespace std;

void helper(int num, string output){
    string str[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(num == 0 || num == 1){
        cout<<output<<endl;
        return;
    }
    if(str[num%10-2].size() == 3){
        helper(num/10, str[num%10-2][0] + output);
        helper(num/10, str[num%10-2][1] + output);
        helper(num/10, str[num%10-2][2] + output);
    }else{
        helper(num/10, str[num%10-2][0] + output);
        helper(num/10, str[num%10-2][1] + output);
        helper(num/10, str[num%10-2][2] + output);
        helper(num/10, str[num%10-2][3] + output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    helper(num, output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}