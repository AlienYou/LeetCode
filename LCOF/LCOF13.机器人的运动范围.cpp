class Solution {
public:
    int movingCount(int m, int n, int k) {
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> que;
        que.push({0, 0});
        visited[0][0] = true;
        while (!que.empty()) {
            auto [curX, curY] = que.front();
            que.pop();
            if (cal(curX) + cal(curY) <= k) {
                res++;
                if (curX  + 1 < m && visited[curX + 1][curY] == false) {
                    visited[curX + 1][curY] = true;
                    que.push({curX + 1, curY});
                }
                if (curY + 1 < n && visited[curX][curY + 1] == false) {
                    visited[curX][curY + 1] = true;
                    que.push({curX, curY + 1});
                }
            }
        }
        return res;
    }

    int cal(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};