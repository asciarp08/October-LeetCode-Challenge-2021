/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN, secondBuy = INT_MIN, firstSell = INT_MIN, secondSell = INT_MIN;
        
        for(auto p:prices){
            firstBuy = max(firstBuy, -p);
            firstSell = max(firstSell, firstBuy+p);
            secondBuy = max(secondBuy, firstSell-p);
            secondSell = max(secondSell, secondBuy+p);
        }
        return secondSell;
    }
};
