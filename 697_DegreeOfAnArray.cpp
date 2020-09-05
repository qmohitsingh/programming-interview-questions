class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, int> map;
        int degree = 0;
        
        unordered_map<int, int> indexMap;
        int min_length = 0;
        
        for (int i=0; i<nums.size(); i++) {
            
            if (!indexMap[nums[i]]) {
                indexMap[nums[i]] = i+1;
            }
            
            map[nums[i]]++;
            if (map[nums[i]] > degree) {
                degree = map[nums[i]];
                min_length = i - indexMap[nums[i]] + 2;
            }else if (map[nums[i]] == degree) {
                degree = map[nums[i]];
                min_length = min(min_length, i - indexMap[nums[i]] + 2);
            }
        }
        
        return min_length;
        
        
    }
};
