class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int i = 0 ;
    int n = matrix.size();
    int j = matrix[0].size() - 1;
    while(i < n && j >= 0){
        if(target == matrix[i][j]){
            return true;
        }
        else if(target > matrix[i][j]){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
    }
};
