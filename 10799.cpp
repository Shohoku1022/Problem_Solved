#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    int ans(0), cur_pipe(0);
    string str;
    getline(cin, str);

    stack<char> st;

    for (auto c : str)
    {
        if (c == '(')
        {
            cur_pipe++;
            ans++;
            st.push(c);
        }
        else if (st.top() == '(' && c == ')')
        {
            cur_pipe--;
            ans--;
            ans += cur_pipe;
            st.push(c);
        }
        else if (st.top() == ')' && c == ')')
        {
            cur_pipe--;
            st.push(c);
        }
    }
    cout << ans;
}