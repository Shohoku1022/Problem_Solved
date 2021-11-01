#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, ans(0);
    cin >> N;
    while (N--)
    {
        stack<int> st;
        string tmp;
        cin >> tmp;

        for (auto c : tmp)
        {
            if (st.empty())
            {
                st.push(c);
                continue;
            }
            else if (st.top() != c)
            {
                st.push(c);
                continue;
            }
            else if (st.top() == c)
            {
                st.pop();
            }
        }
        if (st.empty())
        {
            ans++;
        }
    }
    cout << ans;
}