#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    int t;
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--)
    {
        int board[52][52] = {
            0,
        };
        bool vis[52][52] = {
            0,
        };
        int m, n, k;
        queue<pair<int, int>> Q;
        int bug = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            board[tmp2][tmp1] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && board[i][j] == 1)
                {
                    vis[i][j] = 1;
                    Q.push({i, j});
                    bug++;
                    while (!Q.empty()) //bfs
                    {
                        auto cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;
                            if (board[nx][ny] == 0 || vis[nx][ny] == 1)
                                continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << bug << '\n';
    }
}