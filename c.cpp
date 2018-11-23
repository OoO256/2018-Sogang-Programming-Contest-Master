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

int n;
vector<int>plist;
vector<int>nums;
int MAX = ceil(sqrt(5000000));

void getp() {
	vector<bool>isp(MAX + 1, true);
	isp[0] = false;
	isp[1] = false;

	for (int i = 2; i < MAX + 1; i++)
	{
		if (isp[i] == true)
		{
			for (int j = i * 2; j < MAX + 1; j += i)
			{
				isp[j] = false;
			}
		}
	}

	for (int i = 0; i < MAX + 1; i++)
	{
		if (isp[i] == true)
			plist.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	nums.resize(n);
	for (auto& i : nums)
	{
		cin >> i;
	}

	getp();


	for (auto& num : nums)
	{
		for (int i = 0; i < 332;)
		{
			if (num == 1)
				break;

			if (num % plist[i] == 0)
			{
				num /= plist[i];
				cout << plist[i] << ' ';
			}
			else
			{
				i++;
			}
		}
		if (num  > plist.back())
		{
			cout << num;
		}
		cout << '\n';
	}


	return 0;
}