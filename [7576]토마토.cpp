#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int tobox[1002][1002];
int age[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 방향 벡터
bool rotten = false;
int n, m, ans(0);

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> tobox[i][j];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tobox[i][j] == -1)
            {
                age[i][j] = -1;
            }
            else
            {
                age[i][j] = 0;
                if (tobox[i][j] == 0)
                    rotten = true;
            }
        }
    }

    if (rotten == false)
    {
        cout << 0;
        return 0;
    }
    else
    {
        queue<pair<int, int>> Q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tobox[i][j] == 1) // 토마토가 익은 것마다 queue에 넣기
                {
                    age[i][j] = 1;
                    Q.push({i, j});
                }
            }
        }

        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (age[nx][ny] > 0 || tobox[nx][ny] == -1)
                    continue;
                age[nx][ny] = age[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (age[i][j] == -1)
                {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, age[i][j]); // 알고리즘
            }
        }
    }
    cout << ans - 1;
}