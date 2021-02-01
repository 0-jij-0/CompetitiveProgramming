#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> s;
vector<int> t, v;

struct moves {
	int i, j, d;
	moves() {}
	moves(int _i, int _j, int _d) :
		i(_i), j(_j), d(_d) {}
	ostream & print(ostream &os) {
		os << i << ' ' << j << ' ' << d << endl;
		return os;
	}
};

int main() {
	int n; cin >> n;
	s.resize(n); t.resize(n); v.resize(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; s[i] = { a, i + 1 };
	}
	for (int i = 0; i < n; i++) { cin >> t[i]; }

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	for (int i = 0; i < n; i++) { 
		v[i] = s[i].first - t[i];
	}
	long long sum = 0; bool b = true;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (sum > 0) { b = false; break; }
	}
	if (sum != 0 || !b) { cout << "NO" << endl; }
	else {
		cout << "YES" << endl;
		vector<moves> res;
		int neg = 0, pos = 1;
		while (pos < n) {
			if (v[pos] <= 0) { pos++; continue; }
			if (v[neg] == 0) { neg++; continue; }
			int d = min(v[pos], -v[neg]);
			moves m(s[neg].second, s[pos].second, d); res.push_back(m);
			v[pos] -= d; v[neg] += d;
		}
		cout << res.size() << endl;
		for (auto &x : res) { x.print(cout); }
	}
	cin.ignore(2); return 0;
}