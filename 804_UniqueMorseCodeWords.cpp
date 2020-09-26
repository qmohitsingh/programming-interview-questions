class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string map[26] = {".-","-...","-.-.","-..",".","..-.","--.","....",
                        "..",".---","-.-",".-..","--","-.","---",".--.",
                        "--.-",".-.","...","-","..-","...-",".--","-..-",
                        "-.--","--.."};
        
        unordered_map<string, int> m;
        int ans = 0;
        for (int i=0; i<words.size(); i++) {
            string key = "";
            for (int j=0; j<words[i].length(); j++) {
                key += map[words[i][j]-'a'];
            }
            
            m[key]++;
        }
        
        for (auto val : m) 
            ans += 1;
        
        return ans;
    }
};
