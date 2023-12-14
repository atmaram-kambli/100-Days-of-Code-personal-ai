//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        long long mod = 1000000007;
    public:
    long long countWays(int n, int k){
        if(n == 1) return k;
        
        long long ans = 1, prev = 1;
        for(int i = 1; i < n; i++) {
            long long t = (k-1) * ans;
            ans = (prev + t) % mod;
            prev = t;
        }
        return (ans * k) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
