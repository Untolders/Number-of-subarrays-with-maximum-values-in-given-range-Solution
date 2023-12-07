**********************************************************************************  Question  **************************************************************************************************************************
Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example 1:

Input : 
Arr = {2, 0, 11, 3, 0}
L = 1 and R = 10
Output : 
4
Explanation:
The sub-arrays {2}, {2, 0}, {3} and {3, 0} have maximum in range 1-10.
Example 2:

Input : 
Arr = {3, 4, 1}
L = 2 and R = 4
Output : 
5
Explanation:
The sub-arrays {3}, {3, 4}, {3,4,1}, {4} and {4, 1} have maximum in range 2-4.
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function countSubarrays() that takes an array arr, sizeOfArray (n), element L, integer R, and return the number of subarray with the maximum in range L-R. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
0 ≤ arr[i] ≤ 109
1 ≤ L ≤ R ≤ 109





**********************************************************************************  Solution  **************************************************************************************************************************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
          long long int ans = 0;
        long long int l = 0,tot = 0,lsum = 0,i = 0;
    
        while(i<n){
            if(a[i]>R){
                lsum = lsum + ((l*(l+1))/2);
                ans = ans + (((tot)*(tot+1))/2) - lsum;
                l = 0,lsum = 0,tot=0;
                ++i;
                continue;
            }
            else if(a[i]<L){
                ++l;
                ++tot;
                ++i;
            }
            else{
                lsum = lsum + ((l*(l+1))/2);
                l = 0;
                ++tot;
                ++i;
            }
        }
        lsum = lsum + ((l*(l+1))/2);
        ans = ans + (((tot)*(tot+1))/2) - lsum;
        return ans;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends
