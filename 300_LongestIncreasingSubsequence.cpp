//time complexity: O(nlong) - greedy approach

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) { //O(n)
        
        int k = 0;
        for (int i=0; i<nums.size(); i++) {
            int pos   = lower_bound(nums.begin(), nums.begin()+k, nums[i]) - nums.begin();
            
            nums[pos] = nums[i];
            if (k == pos) {
                k = pos + 1;
            }
        }
        
        return k;
        
    }
    
};
