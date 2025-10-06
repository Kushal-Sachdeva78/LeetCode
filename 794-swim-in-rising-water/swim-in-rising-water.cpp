#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<bool>> seen(n, std::vector<bool>(n, false));
        using T = std::tuple<int,int,int>;
        std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
        pq.push({grid[0][0], 0, 0});
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (seen[r][c]) continue;
            seen[r][c] = true;
            if (r == n - 1 && c == n - 1) return t;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                    pq.push({std::max(t, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};
