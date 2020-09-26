class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int start_row = 0;
        int end_row   = n-1;
        int start_col = 0;
        int end_col   = n-1;
        
        int val = 1;
        while(start_col<=end_col&&start_row<=end_row) {
            
            for (int i=start_col; i<=end_col; i++) {
                matrix[start_row][i] = val++;
            }   
            start_row++;
            
        
            for (int i=start_row; i<=end_row; i++) {
                matrix[i][end_col] = val++;
            }
            end_col--;
            
            for (int i=end_col; i>=start_col; i--) {
                matrix[end_row][i] = val++;
            }
            end_row--;
            
            
            for (int i=end_row; i>=start_row; i--) {
                matrix[i][start_col] = val++;
            }
            start_col++;
        
        }
        
        return matrix;
        
    }
};
