#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
	int price, cap;

	item() {}
	item(int _price, int _cap) :
		price(_price), cap(_cap) {}

	bool operator < (const item &rhs) const { return price > rhs.price; }
};

vector<item> items;
vector<int> group;
int DP[1001][31];

int knapsack(int i, int cap) {
	if (i == items.size() || cap == 0) { return 0; }
	if (DP[i][cap] != -1) { return DP[i][cap]; }

	int a = knapsack(i + 1, cap);
	if (items[i].cap > cap) { DP[i][cap] = a; return a; }
	int b = items[i].price + knapsack(i + 1, cap - items[i].cap);
	DP[i][cap] = (a < b) ? b : a;
	return DP[i][cap];
}

int max_val(int n, int g) {
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < 31; j++) { DP[i][j] = -1; }
	}
	int max = 0;
	for (int i = 0; i < g; i++) {
		max += knapsack(0, group[i]);
	}
	return max;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		items.clear();
		for (int j = 0; j < n; j++) {
			int p, c; cin >> p >> c;
			item it(p, c); items.push_back(it);
		}
		sort(items.begin(), items.end());
		int g; cin >> g;
		group.clear();
		for (int j = 0; j < g; j++) {
			int mw; cin >> mw;
			group.push_back(mw);
		}
		cout << max_val(n, g) << endl;
	}
	cin.ignore(2); return 0;
}