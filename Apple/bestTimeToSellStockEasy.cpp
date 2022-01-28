class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        stack<int>pr;
        int maxProfitAmount = 0;
        pr.push(prices[0]);
        for(int i = 1 ; i < prices.size(); i++){
            if(prices[i] <= pr.top()){
                pr.pop();
                pr.push(prices[i]);
            }
            else{
                int difference = prices[i] - pr.top();
                maxProfitAmount = max(maxProfitAmount,difference);
            }
        }
        return maxProfitAmount;
    }
};
