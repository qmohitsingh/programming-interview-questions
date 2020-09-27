class Solution {
public:
    string removeKdigits(string num, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        int len = num.length();
        
        string result = "";
        
        stack<char> stk;
        
        for (auto c : num) {
            
            
            while( !stk.empty() && stk.top() > c && k > 0) {
                stk.pop();
                k--;
            }
            
            if (stk.empty() && c == '0') continue;
            
            stk.push(c);
            
        }
        
        //remove the largest values from the top stack
        while(!stk.empty() && k--) {
            stk.pop();
        }
        
        if (stk.empty()) return "0";
        
        while (!stk.empty()){
            num[len-1] = stk.top();
            stk.pop();
            len--;
        }
        
        
        return num.substr(len);
        
    }
};
