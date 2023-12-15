//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int fibbo (int n) {
	        int a = 1, b = 2, prev, mod = 1000000007;
	        if(n < 3) return n;
	        
	        for(int i = 3; i <= n; i++) {
	            prev = b;
	            b = (a + b)% mod;
	            a = prev % mod;
	        }
	        return b;
	    }
		int nthPoint(int n){
		    return fibbo(n);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
