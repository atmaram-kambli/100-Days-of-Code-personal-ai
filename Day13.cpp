//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    int mod = 1000000007;
	    long long x = 2;
	    long long y = 3;
	    for(int i = 2; i <= n; i++) {
	        long long temp = (x + y) % mod;
	        x = y;
	        y = temp;
	    }
	    return x;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
