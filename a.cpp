#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>
#include <stack>
#include <string>

#include <functional>
#include <cmath>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	n /= 3;

	if (n < 3)
	{
		cout << 0 << '\n';
	}
	else
	{
		// n dms 1, n-1 ... n-1
		int ans = 0;
		for (int i = 1; i <= n-2; i++)
		{
			ans += n - i - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}