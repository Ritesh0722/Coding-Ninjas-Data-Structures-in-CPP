#include<bits/stdc++.h>
using namespace std;

int countZeros(int n) {
    // Write your code here
    if(n == 0)
        return 1;

    if(n < 10)
        return 0;

    int smallCountZeroes = countZeros(n/10);
    
    if(n%10 == 0){
        return smallCountZeroes + 1;
    }

    return smallCountZeroes;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}