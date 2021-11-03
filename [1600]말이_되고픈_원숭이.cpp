#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; // 그냥 이동
int hx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int hy[8] = {-1, 1, -2, 2, -1, 1, -2, 2}; // 말 이동
int board[202][202];
int dist[202][202][32];
bool vis[202][202];
int k, h, w, ans;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    queue<tuple<int, int, int>> Q;
    cin >> k >> h >> w;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int f = 0; f < k + 1; f++)
            {
                if (i == 0 && j == 0)
                    dist[i][j][f] = 0;
                else
                    dist[i][j][f] = -1;
            }
        }
    }
    Q.push({0, 0, 0});
    vis[0][0] = 1;
    while (!Q.empty())
    {
        int curX, curY, count;
        tie(curX, curY, count) = Q.front();
        Q.pop();
        if (count < k) // 능력을 아직 덜 썼으면?
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = curX + hx[dir];
                int ny = curY + hy[dir];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                    continue;
                if (board[nx][ny] == 1 || dist[nx][ny][count + 1] >= 0 || vis[nx][ny] == 1)
                    continue;
                dist[nx][ny][count + 1] = dist[curX][curY][count] + 1;
                Q.push({nx, ny, count + 1});
                vis[nx][ny] = 1;
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                continue;
            if (board[nx][ny] == 1 || dist[nx][ny][count] >= 0 || vis[nx][ny] == 1)
                continue;
            dist[nx][ny][count] = dist[curX][curY][count] + 1;
            Q.push({nx, ny, count});
            vis[nx][ny] == 1;
        }
    }
    for (int i = 0; i < k + 1; i++)
    {
        if (dist[w - 1][h - 1][i] != -1)
        {
            if (ans == 0 || ans > dist[w - 1][h - 1][i])
                ans = dist[w - 1][h - 1][i];
        }
        else if (i == k && ans == -1)
        {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}