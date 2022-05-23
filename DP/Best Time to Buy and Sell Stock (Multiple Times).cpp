int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            int profit =0;
            
            for(int buy=1; buy>=0 ; buy--)
            {
                if(!buy)
                  profit = max( -prices[i] + dp[i+1][1],dp[i+1][0]) ;
                
                else
                  profit = max( prices[i] + dp[i+1][0], dp[i+1][1]);
                
                dp[i][buy] = profit;
            }
            
            
        }
        
        return dp[0][0];
        
        
    }
