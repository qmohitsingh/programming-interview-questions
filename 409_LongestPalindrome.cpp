class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<int, int> hashMap;
        
        int res = 0;
        for (int i=0; i<s.length(); i++) {
            hashMap[s[i] - 'a']++;
        }
        
        for (auto m : hashMap) {
            res += (m.second/2)*2;
            
            if (res%2 == 0 && m.second%2 == 1){
                res += 1;
            }
        }
        
        return res ;
        
    }
};
