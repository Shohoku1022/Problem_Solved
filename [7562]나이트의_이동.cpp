#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int dy[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
int n;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n--)
    {
        queue<pair<int, int>> Q;
        int l, startf, starts, endf, ends;
        int board[304][304] = {
            -1,
        };
        cin >> l >> startf >> starts >> endf >> ends;
        Q.push({startf, starts});
        board[startf][starts] = 0;
        while (Q.front().X != endf || Q.front().Y != ends)
        {
            auto cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;
                if (board[nx][ny] > 0)
                    continue;
                board[nx][ny] = board[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << board[endf][ends] << '\n';
    }
}