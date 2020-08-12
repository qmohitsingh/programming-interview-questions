class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
//         vector<int> vec(nums.size() + 1);
        
//         vector<int> ans;
        
//         for (int i = 0; i<nums.size(); i++) {
//             if (vec[nums[i]]) ans.push_back(nums[i]);
//             else {
//                 vec[nums[i]] = 1;
//             }
//         }
        
//         return ans;
        nums.insert(nums.begin(), 0); 
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (nums[abs(nums[i])] >= 0)
                nums[abs(nums[i])] = - nums[abs(nums[i])];
            else
                ans.push_back(abs(nums[i]));
        }
        
        
        return ans;
        
    }
};442. Find All Duplicates in an Array
