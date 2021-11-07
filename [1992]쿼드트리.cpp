#include <bits/stdc++.h>
using namespace std;
string board[66];
int n;

void func(int r, int c, int num)
{
    bool isSame = true;
    if (num == 1)
    {
        cout << board[r][c];
        return;
    }
    for (int i = r; i < r + num; i++)
    {
        for (int j = c; j < c + num; j++)
        {
            if (board[r][c] != board[i][j])
            {
                isSame = false;
            }
        }
    }
    if (!isSame)
    {
        cout << "(";
        func(r, c, num / 2);
        func(r, c + num / 2, num / 2);
        func(r + num / 2, c, num / 2);
        func(r + num / 2, c + num / 2, num / 2);
        cout << ")";
    }
    else
    {
        cout << board[r][c];
    }
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    func(0, 0, n);
}