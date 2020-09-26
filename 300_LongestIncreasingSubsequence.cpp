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

//time complexity: O(n^2) - bottom-up approach
class Solution {
    int k = 0;
    //vector<int> memo(10010, -1);
public:
    
    int lengthOfLIS(vector<int>& nums) { //O(n^2)
        
        if (nums.size() == 0) return 0;
        
        vector<int> lis(nums.size(), 1);
        
        int val = 1;
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                    val = max(val, lis[i]);
                }
            }
        }
        
        return val;
        
    }
    
};

//time complexity: O(n^2) - top-down approach
class Solution {
    int k = 0;
    vector<int> A;
    vector<int> memo; 
public:
    
    Solution() {
        memo.assign(10000007,-1);
    }
    
    int lengthOfLIS(vector<int>& nums) { //O(n^2)
        if (nums.size() == 0) return 0;
        
        nums.push_back(INT_MAX);
        A = nums;
        int ans = LIS(nums.size()-1);
        return ans - 1;
        
    }
    
    int LIS(int i) {                                 // O(2^n) overall
      if (i == 0) return 1;
      int &ans = memo[i];
      if (ans != -1) return ans;                     
      ans = 1;         
      for (int j = 0; j < i; ++j)      {          
        if (A[j] < A[i])                            
          ans = max(ans, LIS(j)+1); 
      }
      return ans;
    }
    
};

