class Solution {
    int row[9]={0}, col[9]={0}, box[9]={0};
    inline int bid(int i,int j){ return (i/3)*3 + j/3; }

    bool dfs(vector<vector<char>>& b, vector<pair<int,int>>& cells){
        if(cells.empty()) return true;
        int best=-1, bestMask=0, bestCnt=10;
        for(int k=0;k<(int)cells.size();k++){
            auto [i,j]=cells[k];
            int m = (~(row[i]|col[j]|box[bid(i,j)])) & 0x1FF;
            int cnt = __builtin_popcount((unsigned)m);
            if(cnt==0) return false;
            if(cnt<bestCnt){ bestCnt=cnt; best=k; bestMask=m; if(cnt==1) break; }
        }
        auto cell=cells[best];
        cells[best]=cells.back(); cells.pop_back();
        int i=cell.first, j=cell.second, m=bestMask, k=bid(i,j);
        while(m){
            int lb = m & -m;
            int d = __builtin_ctz((unsigned)lb);
            row[i]^=lb; col[j]^=lb; box[k]^=lb;
            b[i][j] = char('1'+d);
            if(dfs(b,cells)) return true;
            row[i]^=lb; col[j]^=lb; box[k]^=lb;
            b[i][j]='.';
            m-=lb;
        }
        cells.push_back(cell);
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> cells;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') cells.push_back({i,j});
                else{
                    int v = board[i][j]-'1';
                    int m = 1<<v, k=bid(i,j);
                    row[i]|=m; col[j]|=m; box[k]|=m;
                }
            }
        dfs(board, cells);
    }
};
