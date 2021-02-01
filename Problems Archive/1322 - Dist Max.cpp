#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

struct pt {
	ll x, y;
	pt(ll xx = 0, ll yy = 0) :x(xx), y(yy) {}
	bool operator == (pt &a) { return (a.x - x == 0) && (a.y - y == 0); }
};

bool operator < (const pt &a, const pt &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

pt operator-(pt a, pt b) { return pt(a.x - b.x, a.y - b.y); }
ll vec(pt a, pt b) { return a.x*b.y - a.y*b.x; }
ll det(pt a, pt b, pt c) { return vec(b - a, c - a); }

bool right(pt X, pt Y, pt Z) { return (det(X, Y, Z) <= 0); }

vector<pt> convexhull(vector<pt> &ab) {
	int l = (int)ab.size(), i, j = 0, k;
	vector<pt> res(l + 1); if (l < 3) { return ab; }

	for (i = 0; i < l; i++) {
		while (j - 2 >= 0 && right(res[j - 2], res[j - 1], ab[i])) { j--; }
		res[j++] = ab[i];
	}
	k = j;
	for (i = l - 2; i >= 0; i--) {
		while (j - 1 >= k && right(res[j - 2], res[j - 1], ab[i])) { j--; }
		res[j++] = ab[i];
	}
	if (res[j - 1] == res[0]) { j--; }
	return move(vector<pt>(res.begin(), res.begin() + j));
}

ll dist(pt &a, pt &b) { return abs(a.x - b.x) + abs(a.y - b.y); }

ll bruteForce(vector<pt> &v) {
	int n = (int)v.size(); ll res = 0;
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++)
			res = max(res, dist(v[i], v[j]));
	return res;
}

vector<pt> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x.x >> x.y; }
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if (v.size() < 10) { cout << bruteForce(v) << '\n'; return 0; }
	v = convexhull(v); n = (int)v.size(); int i = 0, j = 0;
	while (j + 1 < n && dist(v[j + 1], v[i]) > dist(v[j], v[i])) { j++; }
	ll res = dist(v[i++], v[j]); while (i != n) {
		while (dist(v[(j + 1) % n], v[i]) > dist(v[j], v[i])) { j = (j + 1) % n; }
		res = max(res, dist(v[i++], v[j]));
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}