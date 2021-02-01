#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, cand;

int main() {
	int n, m; cin >> n >> m;
	v.resize(n); cand.resize(n, 0);

	for (int i = 0; i < m; i++) {
		for (auto &x : v) { cin >> x; }
		int idx = max_element(v.begin(), v.end()) - v.begin();
		cand[idx]++;
	}
	int winner = max_element(cand.begin(), cand.end()) - cand.begin();
	cout << winner + 1 << endl; cin.ignore(2); return 0;
}