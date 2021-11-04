#include <bits/stdc++.h>
using namespace std;
int n;
int board[2200][2200];
int ans[3];

void func(int r, int c, int num)
{
    if (num == 1)
    {
        ans[board[r][c]]++;
        return;
    }

    bool isSame = true;
    for (int i = r; i < r + num; i++)
    {
        for (int j = c; j < c + num; j++)
        {
            if (board[r][c] != board[i][j])
                isSame = false;
        }
    }
    if (isSame)
        ans[board[r][c]]++;
    else
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                func(r + i * num / 3, c + j * num / 3, num / 3);
    }
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == -1)
                board[i][j] = 2;
            else
                board[i][j] = tmp;
        }
    }
    func(0, 0, n);
    cout << ans[2] << '\n'
         << ans[0] << '\n'
         << ans[1];
}