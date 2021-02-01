#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<bool> v[2];
set<pair<int, int>> s;

int main() {
	int n, q; cin >> n >> q;
	v[0].resize(n, 0); v[1].resize(n, 0);
	while (q--) {
		int r, c; cin >> r >> c; r--; c--;
		int nr = r ^ 1;
		if (v[r][c]) {
			if (c != 0 && v[nr][c - 1]) {
				pair<int, int> p(c, c - 1);
				if (r) { swap(p.first, p.second); }
				s.erase(p);
			}
			if (v[nr][c]) {
				pair<int, int> p(c, c);
				s.erase(p);
			}
			if (c != n - 1 && v[nr][c + 1]) {
				pair<int, int> p(c, c + 1);
				if (r) { swap(p.first, p.second); }
				s.erase(p);
			}
		}
		else {
			if (c != 0 && v[nr][c - 1]) {
				pair<int, int> p(c, c - 1);
				if (r) { swap(p.first, p.second); }
				s.insert(p);
			}
			if (v[nr][c]) {
				pair<int, int> p(c, c);
				s.insert(p);
			}
			if (c != n - 1 && v[nr][c + 1]) {
				pair<int, int> p(c, c + 1);
				if (r) { swap(p.first, p.second); }
				s.insert(p);
			}
		}
		v[r][c] = !v[r][c];
		cout << (s.empty() ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}