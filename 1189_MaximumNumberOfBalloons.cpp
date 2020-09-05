class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> m;
        
        //initialize 
        m['a'] = 0;
        m['b'] = 0;
        m['l'] = 0;
        m['o'] = 0;
        m['n'] = 0;
        
        for (int i=0; i<text.length(); i++) {
            if (text[i] == 'a' || text[i] == 'b' 
                || text[i] == 'l' || text[i] == 'o' 
                || text[i] == 'n') {
                m[text[i]]++;
            }
                
        }

        
        for (auto b : m) {
            if (b.first == 'l' || b.first == 'o') {
                m[b.first] = b.second/2;
            }
        }
        
        int res = INT_MAX;
        
        for(auto b : m){
            res = min(res, b.second);
        }
        
        return res;
    }
};
