//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f){
        if(n == 1) return {1};
        vector<pair<int, pair<int,int>>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({s[i], {f[i], i+1}});
        }
        sort(v.begin(), v.end());
        long long start = v[0].first, fin =v[0].second.first, ind = v[0].second.second, diff = fin - start;
        vector<int > ans;
        for(int i = 1; i < n; i++) {
            if(v[i].first == v[i-1].first) continue;
            // if(diff >= (v[i].second.first-v[i].first)) {
            if(v[i].second.first < fin) {
                start = v[i].first;
                fin = v[i].second.first;
                ind = v[i].second.second;
                
            if(i == n-1) {
                ans.push_back(ind);
            }
                continue;
            }
            if(v[i].first > fin) {
                start = v[i].first;
                fin = v[i].second.first;
                ans.push_back(ind);
                ind = v[i].second.second;
            }
            if(i == n-1) {
                ans.push_back(ind);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
