#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int totalInstability(int s1, int s2) {
	int res = 0, i = 0, j = 1;
	for (; j < (int)v.size(); i++) {
		if (i == s1 || i == s2) { j = i + 2; continue; }
		if (j == s1 || j == s2) { j++; i--; continue; }
		res += v[j] - v[i]; i = j; j += 2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n <<= 1);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	int res = 1 << 30;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			res = min(res, totalInstability(i, j));

	cout << res << '\n';
}