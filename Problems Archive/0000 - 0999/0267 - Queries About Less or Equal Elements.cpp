#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<pair<int, int>> b;

bool comapre(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.second < p2.second;
}

int main() {
	int n, m; cin >> n >> m;
	a.resize(n); b.resize(m);
	for (auto &x : a) { cin >> x; }
	for (int i = 0; i < m; i++) {
		int a; cin >> a; b[i] = { a, i };
	}
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	vector<int> res(m);
	int i = 0, j = 0;
	while (j != m && i != n) {
		if (a[i] <= b[j].first) { i++; continue; }
		res[b[j].second] = i; j++;
	}
	if (i == n) {
		while (j != m) { res[b[j].second] = n; j++;	}
	}
	for (int i = 0; i < m; i++) {
		cout << res[i];
		if (i + 1 != m) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}