/*
Time complexity: O(v^3)
*/

//Floyd Warshall Algorithm | DP

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<vector<int> > adjMatrix( N+1 , vector<int> (N+1, 10000));
        
        for (int i=0; i<times.size(); i++)  {
            adjMatrix[times[i][0]][times[i][1]] = times[i][2];
        }
        
        
        for (int k = 1; k <= N; k++) // remember that loop order is k->i->j
            for (int i = 1; i <= N; i++) 
                for (int j = 1; j <= N; j++) {
                    
                    if (i==j) 
                        adjMatrix[i][j] = 0;
                    else
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }

        int ret = 0;
        for(int i=1; i<=N; i++){
            if(adjMatrix[K][i]==10000) return -1;
            ret= max(ret, adjMatrix[K][i]);
        }
        
         return ret;
        }
};
