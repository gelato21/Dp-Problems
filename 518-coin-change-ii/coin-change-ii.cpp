class Solution {
public:
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            if(target%coins[0]==0){
                return 1;
            }
            else return 0;
        }

        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        int notTake=f(ind-1, target, coins, dp);
        int take=0;
        if(coins[ind]<=target){
            take=f(ind, target-coins[ind], coins, dp);
        }

        return dp[ind][target]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        vector<int> prev(amount+1, 0);
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                prev[target]=1;
            }
        }

        for(int ind=1;ind<n;ind++){
            vector<int> curr(amount+1, 0);
            for(int target=0;target<=amount;target++){
                int notTake=prev[target];
                int take=0;
                if(coins[ind]<=target){
                    take=curr[target-coins[ind]];
                }

                curr[target]=take+notTake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};