class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> map_b(26, 0);
        
        vector<string> ans;
        
        for (int i=0; i<B.size(); i++) {
            string temp = B[i];
            vector<int> map_c(26, 0);
            for (int j=0; j<temp.length(); j++) {
                map_c[temp[j]-'a']++;
            }
            
            for (int i=0; i<26; i++){
                map_b[i] = max(map_b[i], map_c[i]);
            }
        }
        
        for (int i=0; i<A.size(); i++) {
            vector<int> map_a(26, 0);
            string temp = A[i];
            for (int j=0; j<temp.length(); j++) {
                map_a[temp[j]-'a']++;
            }
            
            bool flag = true;
            for (int i=0; i<26; i++) {
                if (map_b[i] != 0 && map_a[i] < map_b[i]) {
                    flag = false;
                    break;
                }
                    
            }
            
            if (flag) {
                ans.push_back(A[i]);
            }
            
        }
        
        return ans;
        
    }
};
