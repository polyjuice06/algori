#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100001;

int n;
ll segT[N * 4];

void update(int ptr, int l, int r, int i, ll val)
{
    if (i < l || r < i) return;
    if (l == r)
    {
        segT[ptr] += val;
        return;
    }

    update(ptr * 2, l, (l + r) / 2, i, val);
    update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

    segT[ptr] = segT[ptr * 2] + segT[ptr * 2 + 1];
}

ll getans(int ptr, int l, int r, int i, int j)
{
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return segT[ptr];

    return getans(ptr * 2, l, (l + r) / 2, i, j) + getans(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    ll check = 0;
    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        update(1, 1, n, i, a - check);
        check = a;
    }

    int m; cin >> m;
    while (m--)
    {
        int q; cin >> q;
        if (q == 1)
        {
            ll i, j, k;
            cin >> i >> j >> k;
            update(1, 1, n, i, k);
            update(1, 1, n, j + 1, -k);
        }
        else
        {
            ll x;
            cin >> x;
            cout << getans(1, 1, n, 1, x) << '\n';
        }
    }
}

