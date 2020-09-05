class Solution {
public:
    vector<int> partitionLabels(string S) {
            
        vector<int> res;
        
        if (S.length() == 1) { 
            res.push_back(1);
            return res;
        }
        
        vector<int> ch(26);
        
        for (int i=0; i<S.length(); i++) ch[S[i] - 'a'] = i;
        
        int endIndex = 0; int index = 0;
        for (int i=0; i<S.length(); i++) {
            
            endIndex = max(endIndex , ch[S[i] - 'a']);
            
            if (endIndex == i) {
                res.push_back(endIndex - index +1);
                index = i +1 ;
            }
            
            
        }
        
//         int i=0;
//         while(i < S.length()) {
            
//             int endIndex = ch[S[i]-'a'];
            
//             int j = i + 1;
            
//             while( j != endIndex) {
//                 endIndex = max(endIndex, ch[S[j++] - 'a']);
//             }
            
//             res.push_back(j-i+1);
            
//             i = j + 1;
            
//         }
        
        
         return res;
    }
};
