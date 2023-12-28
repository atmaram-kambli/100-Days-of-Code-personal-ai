//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int p = 0, w = 0, pstar = -1, wstar = -1, n = wild.length(), m = pattern.length();
        wild += '_';
        while (p < m) {
            if(pattern[p] == wild[w] || wild[w] == '?') {
                p += 1;
                w += 1;
            }
            else if(wild[w] == '*') {
                wstar = w;
                w += 1;
                pstar = p;
            }
            else if(wstar >= 0) {
                w = wstar + 1;
                pstar += 1;
                p = pstar;
            }
            else {
                return false;
            }
        }
        while(w < n) {
            if(wild[w] != '*') {
                return false;
            }
            w += 1;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
