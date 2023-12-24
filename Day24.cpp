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
    int countIndices(int n, vector<int> &arr) {
        vector <int > brr(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            brr[i] = arr[i];
        }
        sort(brr.begin(), brr.end());
        for(int i = 0; i < n; i++) {
            if(arr[i] != brr[i]) {
                cnt++;
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
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.countIndices(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
