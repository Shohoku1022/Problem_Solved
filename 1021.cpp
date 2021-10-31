// 회전하는 큐
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    deque<int> dq;
    int N, M, ans(0); // 큐의 크기 N, 뽑아내려는 갯수 M
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        dq.push_back(i);

    while (M--)
    {
        int num; // 뽑아내려는 수
        cin >> num;
        bool flag = true;

        for (int i = 0; i <= dq.size() / 2; i++)
        {
            if (dq[i] == num)
            {
                flag = false; // 왼쪽으로 돌리기 , 3
                break;
            }
        }
        while (dq.front() != num)
        {
            if (!flag) // 오른쪽으로 돌리기
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                dq.push_front(dq[dq.size() - 1]);
                dq.pop_back();
            }
            ans++;
        }
        if (dq.front() == num)
            dq.pop_front();
    }
    cout << ans;
}