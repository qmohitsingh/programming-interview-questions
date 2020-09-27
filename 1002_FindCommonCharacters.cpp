class Solution {

public:
    vector<string> commonChars(vector<string>& A) {
        
        vector<string> ans;
        
        vector<int> minChar(26, INT_MAX);
        
        int size = A.size();
        
        if (size == 0) return ans;
        
        for (int i=0; i<size; i++) {
            string temp = A[i];
            
            vector<int> currentMinChar(26, 0);
            for (int i=0; i<temp.length(); i++) {
                currentMinChar[temp[i]-'a']++;
            }
            
            for (int i=0; i<26; i++) {
                minChar[i] = min(minChar[i], currentMinChar[i]);
            }
        }
        
        for (int i=0; i<26; i++) {
            while (minChar[i] > 0) {
                string p;
                p += i+'a';
                ans.push_back(p);
                minChar[i]--;
            }
        }
        
        return ans;
    }
};
