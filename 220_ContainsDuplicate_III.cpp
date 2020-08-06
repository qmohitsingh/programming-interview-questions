Reference : https://www.youtube.com/watch?v=Cu7g9ovYHNI&t=1187s

Solution explained:
1.  We'll need a data structure that could give us efficient access for operations like: get, insert, delete for a given size of k elements, 
    we want it better than a linear time complexity - a self balancing binary search tree comes into picture;
2. We'll still use a set to find the duplicate, and the set size will be k as well, however, each time:
    a. we'll quickly peek the maximum element in the set that is smaller than the current element that we are iterating on, 
       check if their difference is smaller than or equal to t, if so, then we could happily return true, if not, 
    b. then we check the minimum element in this given set that is bigger than the current element that we are iterating on, 
       check if their difference is smaller than or equal to t, if so, then we could happily return true, if not,
    c. we'll add this element into the set;
    d. then we'll do a check to make sure the size of the set is still within k, if not, we'll remove the oldest element from this set.

Time complexity: O(nlog(min(n, k)))
Space complexity: O(min(n, k))

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        if(nums.size() == 0) return false;
        
        if(k==0) return false;
        
        multiset<int> bst;
        for(int i=0; i < nums.size(); i++)
        {
            const auto it = bst.lower_bound(nums[i] - t);
            if(it != bst.end() && abs(*it - nums[i]) <= t)
                return true;
                
            bst.insert(nums[i]);
            
            if(bst.size() > k)
                bst.erase( bst.find(nums[i-k]) );
        }
        
        return false;
    }

};


