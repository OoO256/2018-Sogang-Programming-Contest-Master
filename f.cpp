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

struct card
{
	int num;
	bool poss = true;
	card(int _num, bool _poss) : num(_num), poss(_poss) {};
	card() {};
	bool operator<(const card& rhs) {
		return num < rhs.num;
	}
};

vector<card>me;
vector<int>chulsu;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	me.resize(m, {0, true});
	chulsu.resize(k);

	for (auto& i : me)
		cin >> i.num;
	for (auto& i : chulsu)
		cin >> i;

	sort(me.begin(), me.end());

	for (auto& q : chulsu)
	{
		card cq = card(q, true);
		int l = upper_bound(me.begin(), me.end(), cq, [](card c1, card c2) {return c1.num < c2.num; }) - me.begin();
		while (me[l].poss == false)
		{
			l++;
		}
		cout << me[l].num << '\n';
		me[l].poss = false;
	}

	return 0;
}