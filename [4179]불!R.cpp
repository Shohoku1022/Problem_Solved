#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string maze[1002];
int dist[1002][1002];
int r, c;
int vis[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c;
    queue<pair<int, int>> Q;
    pair<int, int> memo;
    int firecnt = 0;
    for (int i = 0; i < r; i++)
        cin >> maze[i];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (maze[i][j] == 'F')
                Q.push({i, j});
            if (maze[i][j] == 'J')
            {
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
                {
                    cout << 1;
                    return 0;
                }
                memo = {i, j};
            }
            if (maze[i][j] == '#')
                dist[i][j] = -1;
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            firecnt++;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (dist[nx][ny] > 0 || dist[nx][ny] == -1 || maze[nx][ny] == 'F')
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    dist[memo.X][memo.Y] = 0;
    vis[memo.X][memo.Y] = 1;
    Q.push({memo.X, memo.Y});
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        int able = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (firecnt != 4)
            {
                if (vis[nx][ny] == 1 || dist[cur.X][cur.Y] + 1 >= dist[nx][ny] || maze[nx][ny] == 'F' || maze[nx][ny] == '#')
                    continue;
            }
            else
            {
                if (dist[nx][ny] > 0 || dist[nx][ny] == -1 || maze[nx][ny] == 'J')
                    continue;
            }
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            if (nx == r - 1 || ny == c - 1 || nx == 0 || ny == 0)
            {
                cout << dist[nx][ny] + 1;
                return 0;
            }
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
