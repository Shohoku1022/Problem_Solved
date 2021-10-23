#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    stack<int> s;
    list<char> l;
    int n, high(0);
    bool flag = true;
    cin >> n;

    while (n--)
    {
        int num;
        cin >> num;

        if (num > high)
        {
            for (high++; high <= num; high++)
            {
                s.push(high);
                l.push_back('+');
            }
        }
        else // high > num
        {
            if (s.top() != num)
            {
                cout << "NO";
                return 0;
            }
        }
        s.pop();
        l.push_back('-');
        if (high < num)
            high = num;
    }
    for (auto c : l)
    {
        cout << c << '\n';
    }
}