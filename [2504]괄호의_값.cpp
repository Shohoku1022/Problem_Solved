#include <bits/stdc++.h>
using namespace std;

int tmp(1), ans(0);
string str;
stack<char> st;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            tmp *= 2;
            st.push('(');
        }
        else if (str[i] == '[')
        {
            tmp *= 3;
            st.push('[');
        }
        else if (str[i] == ']' && (st.empty() || st.top() != '['))
        {
            cout << 0;
            return 0;
        }
        else if (str[i] == ']' && (st.empty() || st.top() != '['))
        {
            cout << 0;
            return 0;
        }
        else if (str[i] == ')')
        {
            if (str[i - 1] == '(')
            {
                ans += tmp;
            }
            st.pop();
            tmp /= 2;
        }
        else if (str[i] == ']')
        {
            if (str[i - 1] == '[')
            {
                ans += tmp;
            }
            st.pop();
            tmp /= 3;
        }
    }
    if (!st.empty())
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << ans;
    }
}