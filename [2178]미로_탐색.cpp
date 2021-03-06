#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string maze[102];
int n, m;
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dist[i][j] = -1;
    }

    queue<pair<int, int>> Q;
    dist[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); // 00
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0 || maze[nx][ny] != '1')
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[n - 1][m - 1];
}