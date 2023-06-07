#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll x, y;
vector<pll> points;

void cross_point(pll A, pll B, pll C, pll D)
{
	double px = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
	double py = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
	double p = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);

	if (p == 0)
	{
		if (B == C && A <= C) cout << B.first << " " << B.second << '\n';
		else if (A == D && C <= A) cout << A.first << " " << A.second << '\n';
	}
	else
	{
		double a = px / p;
		double b = py / p;

		cout << fixed;
		cout.precision(9);
		cout << a << " " << b;
	}
}

ll CCW(pll P1, pll B, pll C)
{
	ll check = P1.first * B.second + B.first * C.second + C.first * P1.second;
	check -= B.first * P1.second + C.first * B.second + P1.first * C.second;

	if (check > 0) return 1;
	else if (check == 0) return 0;
	else if (check < 0) return -1;
}

void solve(pll P1, pll B, pll C, pll D)
{
	ll a1 = CCW(P1, B, C) * CCW(P1, B, D);
	ll a2 = CCW(C, D, P1) * CCW(C, D, B);

	if (a1 == 0 && a2 == 0)
	{
		if (P1 > B) swap(P1, B);
		if (C > D) swap(C, D);

		if (P1 <= D && B >= C)
		{
			cout << 1 << '\n';
			cross_point(P1, B, C, D);
		}
		else cout << 0 << '\n';
	}
	else
	{
		if (a1 <= 0 && a2 <= 0)
		{
			cout << 1 << '\n';
			cross_point(points[0], points[1], points[2], points[3]);
		}
		else cout << 0 << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
	{
		cin >> x >> y;
		points.push_back({ x,y });
	}

	solve(points[0], points[1], points[2], points[3]);
	return 0;
}
