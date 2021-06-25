/***
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list
by D elements(towards the left).
***/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}

void rotate(int *input, int d, int n)
{
    //Write your code here
    
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = input[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
 
            if (k == i)
                break;
 
            input[j] = input[k];
            j = k;
        }
        input[j] = temp;
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}