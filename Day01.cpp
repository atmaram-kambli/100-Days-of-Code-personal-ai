//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    void solve(Node *root, vector<pair<int, int>> &v) {
        if(root != NULL) {
            solve(root->left, v);
            if(root->left == NULL && root->right == NULL) {
                v.push_back({root->data, 1});
            }
            else {
                v.push_back({root->data, 0});
            }
            solve(root->right,v);
        }
    }
    
    bool isDeadEnd(Node *root)
    {
        if(root == NULL) return false;
        // if(root->left == NULL && root->right == NULL) return true;
        vector<pair<int, int>> v;
        solve(root, v);
        sort(v.begin(), v.end());
        if(v.size() > 1){
            if(v[0].second == 1 && v[0].first == 1 && v[1].first == 2) {
                return true;
            }
        }
        for(int i=1; i<v.size()-1; i++) {
            if((v[i].second == 1) && (v[i].first == v[i-1].first + 1) && (v[i].first == v[i+1].first-1)) {
                return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends
