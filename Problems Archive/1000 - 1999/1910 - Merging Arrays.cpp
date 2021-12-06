#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
	int i = 0, n = (int)a.size();
	int j = 0, m = (int)b.size();
	vector<int> res(n + m);

	while (i < n || j < m) {
		if (j == m || (i != n && a[i] < b[j])) {
			res[i + j] = a[i]; i++;
		}
		else { res[i + j] = b[j]; j++; }
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

	vector<int> res = mergeArrays(a, b);
	for (auto& x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}