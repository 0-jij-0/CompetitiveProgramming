#include <iostream>
#include <vector>
using namespace std;

vector<int> numberOfSmaller(vector<int>& a, vector<int>& b) {
	int n = (int)a.size(), m = (int)b.size();
	vector<int> res(m); int i = 0;

	for (int j = 0; j < m; j++) {
		while (i != n && a[i] < b[j]) { i++; }
		res[j] = i;
	}
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> res = numberOfSmaller(a, b);
	for (auto& x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}