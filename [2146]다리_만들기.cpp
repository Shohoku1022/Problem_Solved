#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[102][102];
int vis[102][102];
int n, minnum(0);
vector<pair<int, int>> v;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    queue<pair<int, int>> Q, SQ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    // -- 입력 끝
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 1) // 육지 탐색
            {
                vis[i][j] = 1;
                Q.push({i, j});
                while (!Q.empty())
                {
                    int vcount = 0; // vector에 중복되게 들어가지 않기 위한 count
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (board[nx][ny] == 0)
                        {
                            if (vcount == 0 && board[cur.X][cur.Y] == 1)
                            {
                                v.push_back({cur.X, cur.Y});
                                vcount++;
                                continue;
                            }
                            else
                                continue;
                        }
                        if (vis[nx][ny] == 1)
                            continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                for (auto xy : v)
                {
                    int dist[n][n];
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            dist[i][j] = -1;
                        }
                    }
                    dist[xy.X][xy.Y] = 0;
                    SQ.push({xy.X, xy.Y});
                    while (!SQ.empty())
                    {
                        auto curr = SQ.front();
                        SQ.pop();
                        for (int dirr = 0; dirr < 4; dirr++)
                        {
                            int nnx = curr.X + dx[dirr];
                            int nny = curr.Y + dy[dirr];
                            if (nnx < 0 || nnx >= n || nny < 0 || nny >= n)
                                continue;
                            if (dist[nnx][nny] >= 0)
                                continue;
                            dist[nnx][nny] = dist[curr.X][curr.Y] + 1;
                            if (vis[nnx][nny] == 0 && board[nnx][nny] == 1)
                            {
                                if (minnum == 0 || minnum > dist[curr.X][curr.Y])
                                    minnum = dist[curr.X][curr.Y];
                            }
                            SQ.push({nnx, nny});
                        }
                    }
                }
                v.clear();
            }
        }
    }
    cout << minnum;
}
