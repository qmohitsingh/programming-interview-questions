//Union Set - DataStructure

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i=0; i<N; i++)
            p[i] = i;
    }
    
    int findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i])); //path compression
    }
    
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) 
                p[y] = x;
            else {
                p[x] = y;
                
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int size = edges.size();
        
        UnionFind d(size+1);
        
        for (int i=0; i<size; i++) {
            
            // cout<<"val1: "<<edges[i][0]<<" root1: "<<d.findSet(edges[i][0])<<endl;
            // cout<<"val1: "<<edges[i][1]<<" root2: "<<d.findSet(edges[i][1])<<endl;                           
             
            if (d.findSet(edges[i][0]) == d.findSet(edges[i][1]))
                return edges[i];
            
            d.unionSet(edges[i][0], edges[i][1]);
            
        }
        
        return {};
    }
};
