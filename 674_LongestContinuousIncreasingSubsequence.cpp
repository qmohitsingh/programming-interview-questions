class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> lis(nums.size(), 1);
        int val = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                lis[i] = lis[i-1] + 1;
            }
            
            val = max(val, lis[i]);
        }
        
        return val;
    }
};
