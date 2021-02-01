#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> v;
int even, odd;
vector<pair<int, int>> p, pp;

bool compare (const pair<int, int> &p1, const pair<int, int> &p2) {
	return (p1.second - p1.first) < (p2.second - p2.first);
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 1; i <= n; i++)
		(i % 2 ? odd : even)++;
	for (auto &x : v) { 
		cin >> x; if (!x) { continue; }
		(x % 2 ? odd : even)--;
	}
	int i = -1, j = 0, res = 0;
	while (j < n) {
		if (!v[j]) { j++; continue; }
		res += (i != -1) && ((v[j] % 2) != (v[i] % 2));
		if (i + 1 == j) { i++; j++; continue; }
		if (i == -1) { pp.push_back({ i, j }); i = j; j++; }
		else { p.push_back({ i, j }); i = j; j++; }
	}
	if (i + 1 != j) { pp.push_back({ i, j }); }
	sort(p.begin(), p.end(), compare);

	for (auto &x : p) {
		if ((v[x.first] % 2) == (v[x.second] % 2) && (x.second - x.first - 1) > (v[x.first] % 2 ? odd : even)) {
			res += 2; continue;
		}
		if ((v[x.first] % 2) == (v[x.second] % 2)) {
			(v[x.second] % 2 ? odd : even) -= x.second - x.first - 1; continue;
		}
	}

	for (auto &x : pp) {
		if (x.first == -1 && x.second == n) { res = n > 1; break; }
		if (x.first == -1 && x.second > (v[x.second] % 2 ? odd : even)) {
			res++; continue;
		}
		if (x.first == -1) {
			(v[x.second] % 2 ? odd : even) -= x.second; continue;
		}
		if (x.second == n && (x.second - x.first - 1) > (v[x.first] % 2 ? odd : even)) {
			res++; continue;
		}
		if (x.second == n) {
			(v[x.first] % 2 ? odd : even) -= x.second - x.first - 1; continue;
		}
	}
	cout << res << endl; cin.ignore(2); return 0;
}