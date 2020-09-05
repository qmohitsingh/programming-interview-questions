class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        int left = 1;
        int right = 1;
        
        vector<int> res(size);
        
        res[0] = 1;
        left = nums[0];
        for (int i=1; i<nums.size(); i++) {
            res[i] = left;
            left *= nums[i];
        }
        
        // for (auto num : res) {
        //     cout<<"num: "<<num<<endl;
        // }
        
        right = nums[size-1];
        for (int i=size-2; i>=0; i--) {
            res[i] = res[i] * right;
            right *= nums[i];
        }
        
        return res;
        
    }
};
