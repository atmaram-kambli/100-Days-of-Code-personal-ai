//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        int items = 1, Xchange = 0, Ychange = 0, i = 1, temp = 0;
        int n = matrix.size(), m = matrix[0].size(), elements = n * m, flag = 2*n-1;
        vector< int> ans;
        // ans.push_back(matrix[0][0]);
        
        while(i != flag) {
            int currentElements = items;
            int x = Xchange, y = Ychange;
            
            while(currentElements && x < n && y >= 0) {
                ans.push_back(matrix[x][y]);
                    x++;
                    y--;
                currentElements--;
                
            }
            if(items >= n || temp == 1) {
                Xchange += 1;
                Ychange = n - 1;
                items -= 1;
                temp = 1;
            } 
            else {
                items += 1;
                Ychange = items-1;
            }
            
            i++;
        }
        if(n != 1) {
            ans.push_back(matrix[n-1][n-1]);
        }
        if(n == 1) {
            ans.push_back(matrix[0][0]);
        }
        return  ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
