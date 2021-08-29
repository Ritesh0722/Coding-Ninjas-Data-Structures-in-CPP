/***
Split Array

Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Groups can be made with any set of elements, i.e. elements need not to be continuous.
And you need to consider each and every element of input array in some group.

Return true, if array can be split according to the above rules, else return false.

Note : You will get marks only if all the test cases are passed.

Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)

Output Format :
true or false

Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2
Sample Output 1 :
false

Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
***/

#include<bits/stdc++.h>
using namespace std;

// bool helper(int* input, int size, int start, int f_sum, int r_sum) 
// { 
//     if (start == size) 
//         return f_sum == r_sum; 
  
//     if (input[start] % 5 == 0) 
//         f_sum += input[start]; 
  
//     else if (input[start] % 3 == 0) 
//         r_sum += input[start]; 
  
//     else
//         return helper(input, size, start + 1, f_sum + input[start], r_sum) || helper(input, size, start + 1, f_sum, r_sum + input[start]); 

//     return helper(input, size, start + 1, f_sum, r_sum); 
// } 

bool helper(int* input, int size, int start, int f_sum, int r_sum) 
{ 
  
    // If reached the end 
    if (start == size) 
        return f_sum == r_sum; 
  
    // If divisible by 5 then add to the left sum 
    if (input[start] % 5 == 0) 
        f_sum += input[start]; 
  
    // If divisible by 3 but not by 5 
    // then add to the right sum 
    else if (input[start] % 3 == 0) 
        r_sum += input[start]; 
  
    // Else it can be added to any of the sub-arrays 
    else  
        // Try adding in both the sub-arrays (one by one) 
        // and check whether the condition satisfies 
        return helper(input, size, start + 1, f_sum + input[start], r_sum)
           || helper(input, size, start + 1, f_sum, r_sum + input[start]); 
  
    // For cases when element is multiple of 3 or 5. 
    return helper(input, size, start + 1, f_sum, r_sum); 
}

bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return helper(input, size, 0, 0, 0); 
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}