#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;

namespace miller_rabin {
	ll mul(ll x, ll y, ll mod) { return (i128)x * y % mod; }
	ll _pow(ll x, ll y, ll p) {
		ll ret = 1, piv = x % p;
		while (y) {
			if (y & 1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(ll x, ll a) {
		if (x % a == 0) return 0;
		ll d = x - 1;
		while (1) {
			ll tmp = _pow(a, d, x);
			if (d & 1) return (tmp != 1 && tmp != x - 1);
			else if (tmp == x - 1) return 0;
			d >>= 1;
		}
	}
	bool isprime(ll x) {
		for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
			if (x == i) return 1;
			if (x > 40 && miller_rabin(x, i)) return 0;
		}
		if (x <= 40) return 0;
		return 1;
	}
}
namespace pollard_rho {
	void rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		if (n % 2 == 0) {
			v.push_back(2);
			rec(n / 2, v);
			return;
		}
		if (miller_rabin::isprime(n)) {
			v.push_back(n);
			return;
		}
		ll a, b, c, g = n;
        auto f = [&](ll x) {
            return (c + miller_rabin::mul(x, x, n)) % n;
        };
        do {
            if (g == n) {
                a = b = rand() % (n - 2) + 2;
                c = rand() % 20 + 1;
            }
            a = f(a);
            b = f(f(b));
            g = gcd(abs(a - b), n);
        } while (g == 1);
		rec(g, v);
		rec(n / g, v);
	}
	vector<ll> factorize(ll n) {
		vector<ll> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
};
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n; cin >> n;
	ll ans = 1;
	ll check = 1;
	ll tmp = 0;
	int start = 0;
	for (auto i : pollard_rho::factorize(n)){
	    if(start == 0 || tmp == i){
	        check++;
	        start = 1;
	    }
	    else{
	        ans *= check;
	        check = 2;
	    }
	    tmp = i;
	}
	ans *= check;
	printf("%lld",ans);
}
