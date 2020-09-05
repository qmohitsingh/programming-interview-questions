class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     
        unordered_map<int,int> hashMap;
        
        int maxSum = 0;
        int sum = 0; 
        
        for (int i = 0; i<nums.size(); i++) {
            
            sum += nums[i] == 0 ? -1 : 1;
            
            if (!sum ) {
                if (maxSum < i+1) maxSum = i+1;
            } else if(hashMap.find(sum) != hashMap.end()) {
                if (maxSum < i - hashMap[sum]) maxSum = i - hashMap[sum];
            } else {
                hashMap[sum] = i;
            }
            
            
        }
        
        return maxSum;
        
        
    }
};
