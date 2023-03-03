#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n,k;
const ll mod = 1e9+7;

ll modular_inverse(int a, int b){
    if(b==0) return 1;
    ll ret = modular_inverse(a,b/2);
    ret = ret * ret % mod;
    if(b%2==1) ret = ret*a%mod;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    ll ans = 1;
    for(int i=1;i<=n;i++) ans = (ans * i)%mod;
    for(int i=1;i<=k;i++) ans = (ans * modular_inverse(i,mod-2)) % mod;
    for(int i=1;i<=n-k;i++) ans = (ans * modular_inverse(i,mod-2)) % mod;
    cout << ans;
    return 0;
}
