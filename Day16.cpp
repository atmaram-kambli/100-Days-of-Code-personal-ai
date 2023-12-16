//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    long long int ans = 3;
    
    if(n == 1) return ans;
    else if(n == 2) ans = pow(n, ans);
    else ans = (1 + (2*n) + (n*(n-1)/2) + (n*(n-1)) +(n*(n-1)*(n-2)/2));
    
    return ans;
}
