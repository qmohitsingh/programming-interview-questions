//left and right traversal
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string result = "";
        string forward = "";
        int open = 0;
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else if ( s[i] == ')') {
                if (!open) continue;
                open--;
            }
        
            forward += s[i];
        }
        //cout<<"forward: "<<forward<<endl;
        for (int i=forward.length()-1; i>=0; i--) {
            if (forward[i] == '(' && open-- > 0) continue;
            result += forward[i];
        }
        //cout<<"result: "<<result<<endl;
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};
