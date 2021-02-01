#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct point { 
	ll x; int i, j; point() {}
	point(ll _x, int _i, int _j) : x(_x), i(_i), j(_j) {}
	bool operator < (const point &rhs) const { return x < rhs.x; }
	operator ll() const { return x; }
};

vector<ll> v;
vector<point> p;

bool noCommon(int i, int j) {
	if (p[i].i == p[j].i) { return false; }
	if (p[i].i == p[j].j) { return false; }
	if (p[i].j == p[j].i) { return false; }
	return p[i].j != p[j].j;
}

int main() {
	int n, x; cin >> n >> x; v.resize(n);
	p.resize(n * (n - 1) / 2); int k = 0;
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			p[k++] = point(v[i] + v[j], i + 1, j + 1);

	sort(p.begin(), p.end());
	int i = 0, j = (int) p.size() - 1;
	while (i < j) {
		if (p[i] + p[j] == x && noCommon(i, j)) {
			cout << p[i].i << ' ' << p[i].j << ' ' << p[j].i << ' ' << p[j].j << '\n';
			cin.ignore(2); return 0;
		}
		(p[i] + p[j] < x) ? i++ : j--;
	}
	cout << "IMPOSSIBLE" << endl;
	cin.ignore(2); return 0;
}