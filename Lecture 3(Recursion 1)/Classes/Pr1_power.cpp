#include<bits/stdc++.h>
using namespace std;

int power(int x, int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int res = 1;
    
    if(n>0){
        // cout<<n<<endl;
		res = x * power(x,n-1);
        // cout<<"c"<<res<<endl;
    }
    
    return res;
}


int main() {
    int x,n;
    cin>>x>>n;
    cout<<power(x,n);
}
