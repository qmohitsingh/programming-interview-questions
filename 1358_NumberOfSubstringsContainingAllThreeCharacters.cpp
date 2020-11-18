//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/


//Time complexity O(n), Space complexity O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int a = 0, b = 0, c = 0;
        
        int ans = 0;
        int len = s.length();
        int low = 0;
        int high= 0;
        while(low < len && low <= high && high <= len) {
            if (a && b && c) {
                ans += len - (high -1);
                if (s[low] == 'a')
                    a--;
                else if (s[low] == 'b')
                    b--;
                else 
                    c--;
                low++;
            } else {
                if (s[high] == 'a')
                    a++;
                else if (s[high] == 'b')
                    b++;
                else 
                    c++;
                high++;
            }
        }
        
        return ans;
    }
};
