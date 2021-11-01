// 요세푸스 문제
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    list<int> lst1;
    list<int> lst2;
    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        lst1.push_back(i);

    while (lst1.size() != 0)
    {
        for (int i = 0; i < K; i++)
        {
            if (i == K - 1)
            {
                lst2.push_back(lst1.front());
                lst1.pop_front();
                break;
            }
            lst1.push_back(lst1.front());
            lst1.pop_front();
        }
    }
    cout << '<';

    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            cout << lst2.front() << '>';
            break;
        }
        cout << lst2.front() << ", ";
        lst2.pop_front();
    }
}