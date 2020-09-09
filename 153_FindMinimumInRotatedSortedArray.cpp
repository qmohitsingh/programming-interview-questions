class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) return -1;
        
        if (size == 1) return nums[0];
        
        int low = 0;
        int high = size - 1;
        
        while(low < high) {
            int mid = low + (high-low)/2;
            if(nums[mid]<=nums[high])
            {
                high=mid;
            }else
            {
                low=mid+1;
            }
                
        }
        return nums[low];
        
    }
};
