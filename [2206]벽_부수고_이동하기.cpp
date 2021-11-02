#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string maze[1002];
int dist[1002][1002][2];
int n, m;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    queue<tuple<int, int, int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    dist[0][0][0] = dist[0][0][1] = 1;
    Q.push({0, 0, 0});

    while (!Q.empty())
    {
        int x, y, broke;
        tie(x, y, broke) = Q.front();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maze[nx][ny] == '0' && dist[nx][ny][0] < 1)
            {
                dist[nx][ny][broke] = dist[x][y][broke] + 1;
                Q.push({x, y, broke});
            }
            if (broke == 0 && maze[nx][ny] == '1' && dist[nx][ny][1] == -1)
            {
                dist[nx][ny][1] = dist[x][y][1] + 1;
            }
        }
    }
}