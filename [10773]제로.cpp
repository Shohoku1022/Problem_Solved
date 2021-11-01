#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int K;
    int sum = 0;
    stack<int> s;
    cin >> K;

    while (K--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (s.size() == 0)
            {
                continue;
            }
            else
            {
                s.pop();
            }
        }
        else
        {
            s.push(num);
        }
    }
    while (s.size() != 0)
    {
        int num = s.top();
        sum += s.top();
        s.pop();
    }

    cout << sum;
}