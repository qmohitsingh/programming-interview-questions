

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int> s; 
        for(int i = 0; i < nums.size(); i++) { 
            s.insert(nums[i]);
        }
        
        vector<int> temp;  
        for(auto i : s) {  
            temp.push_back(i);
        }  
        if (temp.size() == 1) {
            return temp[0];
        }
        if (temp.size() == 2) {
            return max(temp[0], temp[1]);
        } else {
            return temp[temp.size()-3]; 
        }
    }
};
