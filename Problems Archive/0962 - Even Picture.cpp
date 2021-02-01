#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> res;

int main() {
	int n; cin >> n;
	pair<int, int> d1(0, 0), d2(0, 1), d3(1, 0);
	for (int i = 0; i < n + 2; i++) {
		res.push_back(d1); d1.first++; d1.second++;
	}
	for (int i = 0; i < n + 1; i++) {
		res.push_back(d2); d2.first++; d2.second++;
	}
	for (int i = 0; i < n + 1; i++) {
		res.push_back(d3); d3.first++; d3.second++;
	}
	cout << res.size() << endl;
	for (auto &x : res) { cout << x.first << ' ' << x.second << '\n'; }
	cin.ignore(2); return 0;
}