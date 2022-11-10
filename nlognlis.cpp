#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int lis[1000001];
int idx[1000001];
int ans[1000001];
int main() {
    int n; 
    cin >> n;
    int id = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (id == 0) {
            lis[id++] = a[i];
            idx[i] = 0;
        }
        else {
            if (lis[id - 1] < a[i])
            {
                idx[i] = id;
                lis[id++] = a[i];
            }
            else{
                idx[i] = lower_bound(lis, lis + id, a[i]) - lis;
                lis[lower_bound(lis, lis + id, a[i]) - lis] = a[i];
            }
        }
    }
    int cnt = 0;
    cout << id << '\n';
    for (int i = n; i >= 1; i--) {
        if (id == idx[i]+1) {
            ans[cnt++] = a[i];
            id--;
        }
    }
    for (int i = cnt-1; i >=0; i--) cout << ans[i] << ' ';
}