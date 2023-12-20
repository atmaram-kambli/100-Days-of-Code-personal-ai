class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX, ind = 0, min2 = INT_MAX;
        // int *ind = min_element(prices.begin(), prices.end());
        // int min1 = *ind
        for(int i = 0; i < prices.size(); i++) {
            if(min1 > prices[i]) {
                min1 = prices[i];
                ind = i;
            }
        }
        // cout << ind << ' ' << min1 << endl;
        for(int i = 0; i < prices.size(); i++) {
            if(i != ind && min2 > prices[i]) {
                min2 = prices[i];
            }
        }
        cout << min1 << " " << min2 << endl;
        if((min1 + min2) <= money) return money - (min2 + min1);
        else return money;  
    }
};
