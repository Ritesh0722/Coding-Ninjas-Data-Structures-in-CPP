#include<bits/stdc++.h>
using namespace std;

double geometricSum(int k) {
    // Write your code here
    if(k == 0)
        return 1;
    
    float smallGeoSum = geometricSum(k-1);

    return smallGeoSum + (1/pow(2,k));
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}