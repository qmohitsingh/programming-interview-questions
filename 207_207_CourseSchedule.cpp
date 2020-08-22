
/*
Directed Graph : 
*/
class Solution {
    
    bool detectCycle(vector<vector<int>> & adj, vector<int> & visited, int index) {
        
        if (visited[index] == 2) return true;
        
        visited[index] = 2;
        
        for ( int i = 0; i<adj[index].size(); i++) {
                
                if (visited[adj[index][i]] != 1) 
                    if (detectCycle(adj,visited, adj[index][i])) return true;
                
        }
        visited[index] = 1;
        return false;
    }
        
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        for (int i=0; i<prerequisites.size(); i++) {
        
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        }
        
        vector<int> visited(numCourses, 0);
        for (int i=0; i<numCourses; i++) {
            if (visited[i]==0) {
                if (detectCycle(adj,visited, i)) return false;
            }
        }
        
        return true;
        
        
        
    }
};


