#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string maze[1002];
queue<tuple<int, int, int>> Q;
int dist[1002][1002][2]; // 이런 식으로 상태공간을 설정해보았다.
int n, m;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dist[i][j][0] = dist[i][j][1] = -1;
    }

    Q.push({0, 0, 0});
    dist[0][0][0] = dist[0][0][1] = 1;
    while (!Q.empty())
    {
        int curX, curY, broken;
        tie(curX, curY, broken) = Q.front();
        if (curX == n - 1 && curY == m - 1)
        {
            cout << dist[n - 1][m - 1][broken];
            return 0;
        }
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny > m)
                continue;
            if (maze[nx][ny] == '0' && dist[nx][ny][broken] == -1) // 벽을 부수장
            {
                dist[nx][ny][broken] = dist[curX][curY][broken] + 1;
                Q.push({nx, ny, broken});
            }
            if (broken == 0 && maze[nx][ny] == '1' && dist[nx][ny][1] == -1)
            {
                dist[nx][ny][1] = dist[curX][curY][broken] + 1;
                Q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
}