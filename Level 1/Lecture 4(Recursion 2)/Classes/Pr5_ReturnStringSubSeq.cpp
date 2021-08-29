#include<bits/stdc++.h>
using namespace std;

int subsequence(string input, string output[]){
    if(input.empty()){
        output[0] = "\0";
        return 1;
    }

    int smallOutputSize = subsequence(input.substr(1), output);
    for(int i = 0; i < smallOutputSize; i++){
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return (2 * smallOutputSize);
}

int main(){
    string input;
    cin>> input;
    string * output = new string[1000];
    int size = subsequence(input, output);
    for(int i = 0; i < size; i++)
        cout<<output[i]<<endl;
    
    delete output;
}