class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int >arr(26, -1);

        for(int i = 0; i < s.length(); i++) {
            if(arr[s[i]-'a'] == -1)
                arr[s[i]-'a'] = i;
            else 
                ans = max(ans, i - arr[s[i]-'a'] - 1);
        }
        return ans;
    }
};
