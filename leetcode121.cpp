class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    	vector<int> dp(n + 1, 0);
    	//memset(dp,sizeof(dp),0);
    	unsigned d1 = 0;
    	unsigned d2 = 0;
    	int ans = -1;
    	for (int t = n - 1; t >= 0; --t)
    	{
    		if (prices[t] > dp[t+1])
    		{
    			dp[t] = prices[t];
    		}
    		else
    		{
    			dp[t] = dp[t + 1];
    		}
    	}
    	int tt = 0;
    	for (int t = 0; t < n; ++t)
    	{
    		int temp = dp[t] - prices[t];
    		if (temp >= ans)
    		{
    			ans = temp;
    			d1 = t;
    			tt = prices[t];
    		}
    	}
    	
    	if (ans > 0)
    	{
    		return ans;
    	}
    	else
    	{
    		return 0;
    	}
    }
};