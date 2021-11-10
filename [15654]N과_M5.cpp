#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
vector<int> v;
bool isused[10002];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!isused[v[i]])
        {
            arr[k] = v[i];
            isused[v[i]] = 1;
            func(k + 1);
            isused[v[i]] = 0;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    func(0);
}