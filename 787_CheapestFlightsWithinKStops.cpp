/*
Reference : https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/796941/Easy-Djikstra's-Code-with-link-to-best-Djikstra's-Implementation
https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/803779/C%2B%2B-easy-priority-queue
*/


//To Do : use djikstra


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int, int>>> adjList(n);
        
        for (int i=0; i<flights.size(); i++) {
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        cout<<"size: "<<adjList.size()<<endl;
        
//         for (auto v : adjList) {
//             //cout<<"v: "<<v<<endl;
//             for (auto p : v) {
//                 cout<<"pair: "<<p.first<<" "<<p.second<<endl;
//             }
//         }
        
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,src,0}); // distance, source, stops
        unordered_map<int, int> hashMap;
        
        //adjList[src]
        
        while(!pq.empty()) {
            
            auto [dist, v, hops] = pq.top();
            pq.pop();
            
            if (dst == v) return dist;
            
            if (hops > K) continue;
            
            for (auto temp : adjList[v]) {
                pq.push({temp.second+dist, temp.first, hops+1});   
            }
        }
        
        return -1;
        
    }
};


//To Do : use djikstra


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int, int>>> adjList(n);
        int INF = 1e9;
        for (int i=0; i<flights.size(); i++) {
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        cout<<"size: "<<adjList.size()<<endl;
        
//         for (auto v : adjList) {
//             //cout<<"v: "<<v<<endl;
//             for (auto p : v) {
//                 cout<<"pair: "<<p.first<<" "<<p.second<<endl;
//             }
//         }
        
        
        priority_queue<tuple<int,int,int>>pq;
        pq.push({0,src,0}); // distance, source, stops
        
        vector<int> distance(n+1, INF);
        
        distance[src] = 0;
        
        //adjList[src]
        
        while(!pq.empty()) {
            
            auto [dist, v, hops] = pq.top();
            pq.pop();
            
            if (hops > K) continue;
            
            for (auto temp : adjList[v]) {
                
                if (distance[temp.first] > temp.second+dist) {
                    distance[temp.first] = temp.second+dist;
                    pq.push({temp.second+dist, temp.first, hops+1});     
                }
            }
        }
        
        if (distance[dst] - distance[src] == INF) return -1;
        
        return distance[dst] - distance[src];
        
    }
};
