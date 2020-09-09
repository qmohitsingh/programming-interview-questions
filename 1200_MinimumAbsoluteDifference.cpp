class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>> res;
        
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        
        for (int i=1; i<arr.size(); i++)
            minDiff = min(minDiff, arr[i] - arr[i-1]);
        
        for (int i=1; i<arr.size(); i++){
            vector<int> temp;
            temp.push_back(arr[i-1]);
            temp.push_back(arr[i]);
            
            if (arr[i] - arr[i-1] == minDiff)
                res.push_back(temp);
        }
        
        return res;
        
    }
};
