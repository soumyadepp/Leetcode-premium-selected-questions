class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int,int>,bool>mp;
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    mp[{i,j}] = true;
                }
            }
        }
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0 && mp[{i,j}]){
                    for(int k = 0 ; k < matrix[i].size(); k++){
                        matrix[i][k] = 0;
                    }
                    for(int k = 0 ; k < matrix.size(); k++){
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};
