#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string board[102];
bool nvis[102][102];
bool bvis[102][102];
int n, nans(0), bans(0);

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    queue<pair<int, int>> Q;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nvis[i][j] == 0)
            {
                Q.push({i, j});
                nvis[i][j] = 1;
                nans++;
                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (nvis[nx][ny] == 1 || board[cur.X][cur.Y] != board[nx][ny])
                            continue;
                        nvis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bvis[i][j] == 0)
            {
                Q.push({i, j});
                bvis[i][j] = 1;
                bans++;
                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (bvis[nx][ny] == 1)
                            continue;
                        if (board[cur.X][cur.Y] != board[nx][ny])
                        {
                            if ((board[cur.X][cur.Y] == 'R' && board[nx][ny] == 'G') || (board[cur.X][cur.Y] == 'G' && board[nx][ny] == 'R'))
                            {
                            }
                            else
                                continue;
                        }
                        bvis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << nans << ' ' << bans;
}