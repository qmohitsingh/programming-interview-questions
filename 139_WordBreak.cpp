class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, int> map;
        
        int maxLen = 0;
        
        for (int i=0; i<wordDict.size(); i++) {
            map[wordDict[i]] = 1;
            maxLen = maxLen < wordDict[i].length() ? wordDict[i].length() : maxLen;
            //maxLen = max(maxLen, wordDict[i].length());
        }
        
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            //cout<<"i: "<<i<<endl;
            
            for (int j = i; j >=0; j--) {
                //cout<<"j: "<<j<<" str: "<<s.substr(j, i-j)<<endl;
                if (i-j > maxLen) continue; //pruning
                if (dp[j]
                        &&
                        map[s.substr(j, i-j)]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        // for (auto d : dp) {
        //     cout<<" "<<d;
        // }
        //cout<<endl;
        //CommonUtils.printArray(dp);
        return dp[n];
     }
        
};
