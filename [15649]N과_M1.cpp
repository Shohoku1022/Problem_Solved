#include <bits/stdc++.h>
using namespace std;
int n, m; // 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
int arr[10];
bool isused[10];

void func(int k)
{
    if (k == m) // k가 다 탐색했을 때
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i]) // 아직 배열에 들어가지 않았을 경우.
        {
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    func(0);
}