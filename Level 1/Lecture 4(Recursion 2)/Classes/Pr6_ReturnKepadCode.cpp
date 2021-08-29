#include<bits/stdc++.h>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
   string str[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    int smallOutputSize = keypad(num/10, output);
    int keyStr = num%10-2;

    string temp[1000];
    int k = 0;

    for(int j = 0; j < smallOutputSize; j++){
        for(int i = 0; i < str[keyStr].size(); i++){
            temp[k] = output[j] + str[keyStr][i];
            k++;
        }
    }
    for(int i = 0; i < k; i++){
        output[i] = temp[i];
    }
    return smallOutputSize * str[keyStr].size();
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}