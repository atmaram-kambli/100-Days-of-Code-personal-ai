//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int maxHappy(int n, vector<int> &a, int m, vector<int> &b) {
        int cnt = 0;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int j = 0;
        for(int i = 0; i < n && j < m; i++) {
            if(b[j] <= a[i]) {
                cnt++;
                j++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> bags(n);
        Array::input(bags,n);
        
        
        int m;
        scanf("%d",&m);
        
        
        vector<int> requirement(m);
        Array::input(requirement,m);
        
        Solution obj;
        int res = obj.maxHappy(n, bags, m, requirement);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
