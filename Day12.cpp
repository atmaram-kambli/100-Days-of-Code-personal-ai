class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int ind1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(max1 < nums[i]) {
                max1 = nums[i];
                ind1 = i;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i != ind1 && max2 < nums[i]) {
                max2 = nums[i];
            }
        }
        return ((max1-1) * (max2-1));
    }
};
