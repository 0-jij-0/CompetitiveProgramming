#include <iostream>
#include <vector>
using namespace std;

struct cons {
	vector<int> a, c;
};

vector<cons> con;
vector<int> cc, ca;
int n, g, m;

int distc(int i, int j) {
	if (i < 0) { return m + 1; }
	if (i >= j) { return i - j; }
	return n + i - j;
}

int dista(int i, int j) {
	if (i < 0) { return m + 1; }
	if (i > j) { return n + j - i; }
	return j - i;
}

void compute_last() {
	vector<int> res; res.resize(g, 0);
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (!con[i].a.empty()) { last = i; }
		ca[i] = last;
	}
	for (int i = 0; i < n; i++) {
		if (ca[i] != -1) { break; }
		ca[i] = last;
	}
	last = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (!con[i].c.empty()) { last = i; }
		cc[i] = last;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (cc[i] != -1) { break; }
		cc[i] = last;
	}
	
	for (int i = 0; i < n; i++) {
		int d1 = distc(cc[i], i), d2 = dista(ca[i], i);
		if (d1 <= m || d2 <= m) {
			if (d1 == d2) {
				for (unsigned int j = 0; j < con[cc[i]].c.size(); j++) {
					res[con[cc[i]].c[j]]++;
				}
				for (unsigned int j = 0; j < con[ca[i]].a.size(); j++) {
					res[con[ca[i]].a[j]]++;
				}
			}
			else if (d1 < d2) {
				for (unsigned int j = 0; j < con[cc[i]].c.size(); j++) {
					res[con[cc[i]].c[j]]++;
				}
			}
			else {
				for (unsigned int j = 0; j < con[ca[i]].a.size(); j++) {
					res[con[ca[i]].a[j]]++;
				}
			}
		}
	}

	for (int i = 0; i < g; i++) {
		cout << res[i];
		if (i + 1 != g) { cout << ' '; }
		else { cout << endl; }
	}
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> g >> m;
		con.clear(); cc.clear(); ca.clear();
		con.resize(n); cc.resize(n); ca.resize(n);
		for (int j = 0; j < g; j++) {
			int h; char c; cin >> h >> c;
			int mn = m % n;
			int idx = (c == 'C') ? (h + mn - 1) % n : (h - mn + n - 1) % n;
			if (c == 'C') { con[idx].c.push_back(j); }
			else { con[idx].a.push_back(j); }
		}
		cout << "Case #" << i + 1 << ": ";
		compute_last();
	}
	cin.ignore(2); return 0;
}