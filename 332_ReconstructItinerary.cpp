class Solution {
public:
    
    vector<string> ans;
    void dfs(map<string, multiset<string>>& adjList, string src) {
        
        //cout<<"src: "<<src<<endl;
        while(adjList[src].size()) {
            auto node = *adjList[src].begin();
            adjList[src].erase(adjList[src].begin());
            dfs(adjList, node);
        }
        ans.push_back(src);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string, multiset<string>> adjList;
        for (auto ticket : tickets) adjList[ticket[0]].insert(ticket[1]);
        
        for (auto m : adjList) {
            cout<<m.first<<" ->";
            
            for(auto i=m.second.begin(); i != m.second.end(); i++) {
                cout<<*i <<"->";
            }
            cout<<endl;
        }
        
        dfs(adjList, "JFK");
        
        for (auto str : ans)
            cout<<str<<" ";
        cout<<endl;
        
        return vector<string>(ans.rbegin(), ans.rend());
    }
};
