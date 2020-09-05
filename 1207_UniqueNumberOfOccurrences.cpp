class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for (int i=0; i<arr.size(); i++)
            m[arr[i]]++;
        
        set<int> s;
        for (auto v: m)
            s.insert(v.first);
        
        return s.size() == m.size();
    }
};
