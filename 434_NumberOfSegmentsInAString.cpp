class Solution {
public:
    
    vector<string> split (const string &s, char delim) {
        vector<string> result;
        stringstream ss (s);
        string item;

        while (getline (ss, item, delim)) {
            
            if (item != "")
                result.push_back (item);
        }

        return result;
    }

    
    int countSegments(string s) {
        
        vector<string> arr = split(s,' ');
        
        int size = arr.size();
        
        return size;
    }
};
