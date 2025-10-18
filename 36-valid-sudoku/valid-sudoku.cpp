class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9]={0}, col[9]={0}, box[9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c=='.') continue;
                int v = c-'1', m = 1<<v, k = (i/3)*3 + j/3;
                if((row[i]&m) || (col[j]&m) || (box[k]&m)) return false;
                row[i]|=m; col[j]|=m; box[k]|=m;
            }
        }
        return true;
    }
};
