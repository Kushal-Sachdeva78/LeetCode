#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0)), atl(m, vector<int>(n, 0));
        auto bfs = [&](queue<pair<int,int>> q, vector<vector<int>>& vis) {
            while(!q.empty()){
                auto [r,c] = q.front(); q.pop();
                static int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
                for(auto& k:d){
                    int nr=r+k[0], nc=c+k[1];
                    if(nr<0||nr>=m||nc<0||nc>=n) continue;
                    if(vis[nr][nc]) continue;
                    if(heights[nr][nc] < heights[r][c]) continue;
                    vis[nr][nc]=1; q.push({nr,nc});
                }
            }
        };

        queue<pair<int,int>> qp, qa;
        for(int c=0;c<n;++c){ pac[0][c]=1; qp.push({0,c}); atl[m-1][c]=1; qa.push({m-1,c}); }
        for(int r=0;r<m;++r){ pac[r][0]=1; qp.push({r,0}); atl[r][n-1]=1; qa.push({r,n-1}); }

        bfs(qp, pac);
        bfs(qa, atl);

        vector<vector<int>> res;
        for(int r=0;r<m;++r)
            for(int c=0;c<n;++c)
                if(pac[r][c] && atl[r][c]) res.push_back({r,c});
        return res;
    }
};
