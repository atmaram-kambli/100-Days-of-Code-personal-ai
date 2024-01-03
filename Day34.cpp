//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int cnt = INT_MAX;
        int arr[3] = {0};
        for(int i = 0; i < s.length(); i++) {
            arr[s[i]-'0']++;
            int tcnt = 0, a[3] = {0};
            for(int j = i; j < s.length(); j++) {
                a[s[j]-'0'] = 1;
                tcnt++;
                if(a[0] && a[1] && a[2]) {
                    if(tcnt == 3) {
                        return 3;
                    }
                    cnt = min(cnt, tcnt);
                    break;
                }
            } 
        }
        for(auto it : arr) if(it == 0) return -1;
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
