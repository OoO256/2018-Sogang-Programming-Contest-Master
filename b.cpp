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

int num_node, num_edge, money;
vector<int>bill;
vector<vector<int>>adj;
// first가 하는거
vector<int>vis;

int getmin(const int curr) {
	vis[curr] = true;

	int mincost = bill[curr];

	for (auto& next : adj[curr])
	{
		if (vis[next] == false)
		{
			mincost = min(mincost,getmin(next));
		}
	}	
	return mincost;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num_node >> num_edge >> money;
	bill.resize(num_node);
	adj.resize(num_node);
	vis.resize(num_node, false);
	for (auto& i : bill)
	{
		cin >> i;
	}

	int s1, s2;
	for (int i = 0; i < num_edge; i++)
	{
		cin >> s1 >> s2;
		s1--;
		s2--;
		adj[s1].push_back(s2);
		adj[s2].push_back(s1);
	}

	int cost=0;
	for (int i = 0; i < num_node; i++)
	{
		if (vis[i] == false)
		{
			cost += getmin(i);
		}
	}
	
	if (money >= cost)
	{

		cout << cost << '\n';
	}
	else
	{
		cout << "Oh no\n";
	}
	return 0;
}