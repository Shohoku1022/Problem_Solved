#include <utility>
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int n, m, cnt(0), area(0); // 세로 크기와 가로 크기
int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 1)
            {
                vis[i][j] = 1;
                Q.push({i, j});
                cnt++;
                int tmp = 1;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop(); // 이제 탐색해냈으니 빼내자잉
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] != 1)
                            continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                        tmp++;
                    }
                }
                if (area < tmp)
                {
                    area = tmp;
                }
            }
        }
    }
    cout << cnt << '\n'
         << area;
}