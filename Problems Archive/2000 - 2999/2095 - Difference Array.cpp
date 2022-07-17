#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		if (v.front() == v.back()) { cout << 0 << '\n'; continue; }

		int curDup = 0, nextDup = 0, z = 0;
		vector<int> nextV;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) { z++; continue; }
			if (i == 0) { nextV.push_back(v[i]); continue; }

			if (v[i] == v[i - 1]) { curDup++; }
			else { nextV.push_back(v[i]); }
		}		
		v = move(nextV); n = (int)v.size();

		while (n > 1) {
			set<int> s;
			for (int i = 1; i < n; i++) {
				if (s.count(v[i] - v[i - 1])) { nextDup++; }
				else { s.insert(v[i] - v[i - 1]); }
			}
			if (z && s.count(v[0])) { nextDup++; }
			else if (z) { s.insert(v[0]); }

			z = max(0, (z - 1)) + curDup;
			curDup = nextDup; nextDup = 0;
			v = move(vector<int>(s.begin(), s.end()));
			n = (int)v.size();
		}

		if (curDup == 0) { cout << v.front() << '\n'; }
		else { cout << (z ? v.front() : 0) << '\n'; }
	}
}