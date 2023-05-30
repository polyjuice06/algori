#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[10];
ll m[10];

pair<ll,pair<ll,ll>> exp_gcd(ll x, ll y){
    if(y==0) return {x,{1,0}};
    pair<ll,pair<ll,ll>> res = exp_gcd(y, x%y);
    ll p,q,r;
    p = res.first;
    q = res.second.first;
    r = res.second.second;
    return {p,{r,q-(x/y)*r}};
}

ll gcd(ll x, ll y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main()
{
    for(int i=0;i<3;i++){
        scanf("%lld %lld",&a[i],&m[i]);
    }
    ll a_0 = a[0];
    ll m_0 = m[0];
    a_0 %= m_0;
    for(int i=1;i<3;i++){
        ll a_1 = a[i];
        ll m_1 = m[i];
        ll G = gcd(max(m_0,m_1),min(m_0,m_1));
        if(a_0%G != a_1%G){
            printf("-1");
            return 0;
        }
        ll p,q;
        auto ret = exp_gcd(m_0/G,m_1/G);
        p = ret.second.first;
        q = ret.second.second;
        ll mod = m_0 * m_1 / G;
        a_0 = (a_0 * (m_1/G) % mod) * q % mod + (a_1*(m_0/G)%mod)*p % mod;
        a_0 = (a_0 + mod) % mod;
        m_0 = mod;
    }
    printf("%lld %lld",a_0,m_0);
    return 0;
}
