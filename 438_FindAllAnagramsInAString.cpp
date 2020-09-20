class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios::sync_with_stdio(0);
        cin.tie(0);
 
        
        vector<int> ans;
        vector<int> phash(26, 0);
        vector<int> hash(26, 0);
        
        long long window = p.length();
        long long len = s.length();
        
        long long left = 0, right = 0;
        
        if (len < window) return ans;
        
        while(right<window) {
            phash[p[right] - 'a'] += 1;
            hash[s[right++] - 'a'] += 1;
        }
        
        right -=1;
        
        while (right<len) {
            if (phash == hash) ans.push_back(left);
            
            right += 1;
            if (right != len) hash[s[right] - 'a'] += 1;
            
            hash[s[left] - 'a'] -= 1;
            
            left += 1;
            
        }
        
        return ans;
    }
};
