class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if (s.length() == 0) return true;
        
        int ptr = 0;
        for (int i=0; i<t.length(); i++) {
            
            if (s[ptr] == t[i]) {
                ptr++;
            }
            
            if (ptr >= s.size()) return true;
            
            //cout<<"ptr: "<<ptr<<" size: "<<s.size()<<endl;
        }
        
        return false;
        
    }
};
