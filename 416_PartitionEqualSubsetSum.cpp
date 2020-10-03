class Solution {
    
    bool subSetSum(vector<int>& nums, int sum) {
        
        int rows = nums.size();
        
        vector<vector<bool>> dp(rows+1, vector<bool>(sum+1));
        
        for (int i=0; i<=rows; i++)
            dp[i][0] = true;
        for (int i=1; i<=sum; i++)
            dp[0][i] = false;
        
        //cout<<"sum : "<<sum<<endl;
        
        for (int i=1; i<=rows; i++)
            for (int j=1; j<=sum; j++) {
                
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        
        return dp[rows][sum];
        
    }
    
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n == 0)
            return false;
        
        int sum = 0;
        for (auto num : nums)
            sum += num;
        
        if (sum % 2 == 1)
            return false;
        
        return subSetSum(nums, sum/2);
        
    }
    
};
