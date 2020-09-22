class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        
        if (hand.size()%W != 0) return false;
        
        //O(N)
        unordered_map<int, int> vec; 
        
        for (int i=0; i<hand.size(); i++) {
            vec[hand[i]]++;
        }
        //NlogN
        sort(hand.begin(), hand.end());
        
        for (int i=0; i< hand.size(); i++) { //O(N)
            
            if (!vec[hand[i]]) continue;
            
            int num = vec[hand[i]];
            
            for (int j=0; j<W; j++) {
                if (vec[hand[i]+j] < num) return false;
                vec[hand[i]+j] = vec[hand[i]+j] - num;
            }
        }
        
        return true;
        
    }
};

   
