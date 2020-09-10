class Solution {
public:
    string longestWord(vector<string>& words) {
        
        //nlogn
        sort(words.begin(), words.end());
        unordered_map<string, int> hashMap;
        
        string result = "";
        
        for (auto w : words) {
            if (w.length() == 1 || hashMap[w.substr(0, w.length()-1)]) {
                if (w.length() > result.length()) result = w;
                hashMap[w] = 1;
            }
        }
        
        return result;
        
    }
};
