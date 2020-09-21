class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<pair<int, int>> trusted(N+1, {0,0});
        
        for (int i = 0; i<trust.size(); i++) {
            trusted[trust[i][0]].first++;
            trusted[trust[i][1]].second++;
            
        }
        
        
        for (int i = 1; i<=N; i++) {
            if (trusted[i].second == N-1 && trusted[i].first == 0) return i;
        }

        
        return -1;
        
    }
};
