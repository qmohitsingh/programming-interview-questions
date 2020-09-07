/*
Reference: https://leetcode.com/problems/merge-intervals/discuss/833855/c%2B%2B-or-faster-than-99.97-or-deque-data-structure-or-easy-solution-or-understandable
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> vec;
        vector<vector<int>> res;
        
        if(intervals.size()==0) return res;
        
        for (int i=0; i<intervals.size(); i++)
            vec.push_back({intervals[i][0], intervals[i][1]});
        
        //sort intervals.
        sort(vec.begin(), vec.end());
        
        deque<pair<int,int>> Q;
    
        //insert all pairs in deque
        for(int i=0; i<vec.size(); i++){
            Q.push_back(vec[i]);
        }
        
        cout<<"size: "<<Q.size()<<endl;
        
        while(!Q.empty()) {
            pair<int,int> p1 = Q.front();
            Q.pop_front();
            while(true && !Q.empty()) {
                pair<int, int> p2 = Q.front();
                if (p1.second >= p2.second) {
                    Q.pop_front();
                    continue;
                } else if(p1.second >= p2.first) {
                    Q.pop_front();
                    Q.push_front(make_pair(p1.first, p2.second));
                    break;
                } else {
                    res.push_back(vector<int>{p1.first, p1.second});
                    break;
                }
            }
            if (Q.size() == 0)
                    res.push_back(vector<int>{p1.first, p1.second});
        } 
        
        return res;
        
    }
};
