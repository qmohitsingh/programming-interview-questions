class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int index = 0;
        for (int i=0; i<A.size(); i++) {
            if (A[i]%2 == 0) {
                int temp = A[i];
                A[i] = A[index];
                A[index++] = temp;
            }
        }
        
        return A;
    }
};
