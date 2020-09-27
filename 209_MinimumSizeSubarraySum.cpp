class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int size = nums.size();
        
        int sum = 0;
        int left = 0;
        int ans = INT_MAX;
        
        for (int i=0; i<size; i++) {
            sum += nums[i];
            
            while (sum >= s) {
                ans = min(ans, i - left + 1);
                sum -= nums[left];
                left++;
            }
            
        }
        
        return ans == INT_MAX ? 0 : ans;
        
    }
};
