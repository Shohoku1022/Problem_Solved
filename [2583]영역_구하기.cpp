#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[102][102];
int vis[102][102];
vector<int> v;
int n, m, k, cnt;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    stack<pair<int, int>> st;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int fx, fy, sx, sy, width, height;
        cin >> fx >> fy >> sx >> sy;
        width = sx - fx;
        height = sy - fy;
        for (int j = m - sy; j < m - sy + height; j++)
        {
            for (int k = fx; k < fx + width; k++)
            {
                board[j][k] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 0)
            {
                int pcnt = 1;
                st.push({i, j});
                vis[i][j] = 1;
                cnt++;
                while (!st.empty())
                {
                    auto cur = st.top();
                    st.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if (board[nx][ny] == 1 || vis[nx][ny] == 1)
                            continue;
                        st.push({nx, ny});
                        vis[nx][ny] = 1;
                        pcnt++;
                    }
                }
                v.push_back(pcnt);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for (auto c : v)
        cout << c << ' ';
}