#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int maxTeams(int &s) {
	int i = 0, j = (int)v.size() - 1;
	int res = 0; while (i < j) {
		if (v[i] + v[j] < s) { i++; continue; }
		if (v[i] + v[j] > s) { j--; continue; }
		i++; j--; res++;
	}
	return res;
}

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end()); int res = 0;
		for (int s = 2; s <= 100; s++)
			res = max(res, maxTeams(s));
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}