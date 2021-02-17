#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

struct Lawnmower {
	string name; int p, c, t, r; Lawnmower() {}
	Lawnmower(string _s, int _p, int _c, int _t, int _r) :
		name(_s), p(_p), c(_c), t(_t), r(_r) {}

	bool operator <(const Lawnmower &rhs) const { return p < rhs.p; }
};

vector<Lawnmower> v;

void readLawnmower(string &s) {
	int i = 0, j = 0, n = (int)s.size();
	vector<string> a;
	while (j != n) {
		if (s[j] != ',') { j++; continue; }
		a.push_back(s.substr(i, j - i)); i = j = j + 1;
	}
	a.push_back(s.substr(i, n - i));
	v.push_back(Lawnmower(a[0], stoi(a[1]), stoi(a[2]), stoi(a[3]), stoi(a[4])));
}

bool check(Lawnmower &x, int l) { return ((10080ll * x.c * x.t) / (x.t + x.r)) >= l; }

int main() {
	int l; int m; cin >> l >> m;
	string s; getline(cin, s);
	for (int i = 0; i < m; i++) { 
		getline(cin, s); readLawnmower(s);
	}
	vector<string> res; int minPrice = 100001;
	for (int i = 0; i < m; i++) {
		if (!check(v[i], l)) { continue; }
		if (v[i].p > minPrice) { continue; }
		if (v[i].p == minPrice) { res.push_back(v[i].name); continue; }
		res.clear(); res.push_back(v[i].name); minPrice = v[i].p;
	}
	
	if (res.empty()) { cout << "no such mower" << endl; }
	for (auto &x : res) { cout << x << endl; }
	cin.ignore(2); return 0;
		
}