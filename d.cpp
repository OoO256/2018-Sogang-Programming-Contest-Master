#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>
#include <stack>
#include <string>

#include <functional>
#include <cmath>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n, k;
vector<ll>l;
vector<ll>cum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	l.resize(n);
	for (auto& i : l)
	{
		cin >> i;
	}
	l.push_back(INT32_MAX);
	sort(l.begin(), l.end());

	cum.resize(n, 0);
	cum[0] = l[0];
	for (int i = 1; i < n; i++)
	{
		cum[i] = l[i] + cum[i - 1];
	}

	ll i;
	for (i = 0; i < n; i++)
	{
		if (l[i + 1] * (i + 1) - cum[i] >= k)
			break;
	}

	ll ans = 0;
	if (i == 0)
	{
		ans = l[0] + k;
	}
	else
	{
		ans = l[i] + (k - l[i] * (i)+cum[i - 1]) / (i+1);
	}
	cout << ans << '\n';
	return 0;
}