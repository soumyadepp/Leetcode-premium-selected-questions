class Solution {
public:
  bool existHelper(vector<vector<char>>&board,string& word,int i,int j,int wordIdx){
       if(wordIdx == word.size())
          return true;
      if(i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1)
          return false;
      if(word[wordIdx] != board[i][j])
          return false;
      
      board[i][j] = '*';
      bool ans = existHelper(board,word,i + 1,j,wordIdx + 1) || 
          existHelper(board,word,i,j + 1,wordIdx + 1) || 
          existHelper(board,word,i - 1,j,wordIdx + 1)||
          existHelper(board,word,i,j - 1,wordIdx + 1);
      board[i][j] = word[wordIdx];
      
      return ans;
  }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(existHelper(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
