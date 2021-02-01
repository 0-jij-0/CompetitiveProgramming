#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <set>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct rect {
	ll x1, x2, h; rect() {}
	rect(ll _x1, ll _x2, ll _h) : x1(_x1), x2(_x2), h(_h) {}
};

vector<rect> v;

inline bool inter(ll &x1, ll &x2, ll y1, ll y2) {
	if (y1 >= x1 && y1 <= x2) { return true; }
	if (y2 >= x1 && y2 <= x2) { return true; }
	if (x1 >= y1 && x1 <= y2) { return true; }
	if (x2 >= y1 && x2 <= y2) { return true; }
	return false;
}

int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");

	int T; ifs >> T;
	for (int t = 1; t <= T; t++) {
		int n, k; ifs >> n >> k; v.resize(n);
		for (int i = 0; i < k; i++) ifs >> v[i].x1;
		ll AL, BL, CL, DL; ifs >> AL >> BL >> CL >> DL;
		for (int i = 0; i < k; i++) ifs >> v[i].x2;
		ll AW, BW, CW, DW; ifs >> AW >> BW >> CW >> DW;
		for (int i = 0; i < k; i++) ifs >> v[i].h;
		ll AH, BH, CH, DH; ifs >> AH >> BH >> CH >> DH;

		for (int i = k; i < n; i++) {
			v[i].x1 = 1 + ((v[i - 2].x1 * AL) % DL + (v[i - 1].x1 * BL) % DL + CL) % DL;
			v[i].x2 = 1 + ((v[i - 2].x2 * AW) % DW + (v[i - 1].x2 * BW) % DW + CW) % DW;
			v[i].h = 1 + ((v[i - 2].h * AH) % DH + (v[i - 1].h * BH) % DH + CH) % DH;
		}

		set<pair<ll, ll>> seg; ll res = 1, p = 0;
		for (int i = 0; i < n; i++) {
			v[i].x2 += v[i].x1; if (seg.empty()) {
				seg.insert({ v[i].x1, v[i].x2 });
				p += (2 * (v[i].x2 - v[i].x1 + v[i].h)) % mod;
				p %= mod; res = (res * p) % mod; continue;
			}
			auto it = seg.upper_bound({ v[i].x1, 0 });
			if (it != seg.begin()) { it--; }
			vector<set<pair<ll, ll>>::iterator> rem;
			if (inter(v[i].x1, v[i].x2, it->first, it->second)) { rem.push_back(it); }
			it++; while (it != seg.end() && inter(v[i].x1, v[i].x2, it->first, it->second)) { rem.push_back(it++); }
			if (rem.empty()) {
				seg.insert({ v[i].x1, v[i].x2 });
				p += (2 * (v[i].x2 - v[i].x1 + v[i].h)) % mod;
				p %= mod; res = (res * p) % mod; continue;
			}
			if (rem.front()->first > v[i].x1) { p = (p + 2 * (rem.front()->first - v[i].x1)) % mod; }
			if (rem.back()->second < v[i].x2) { p = (p + 2 * (v[i].x2 - rem.back()->second)) % mod; }
			for (int j = 1; j < (int)rem.size(); j++)
				p = (p + 2 * (rem[j]->first - rem[j - 1]->second - v[i].h) + mod) % mod;

			pair<ll, ll> newR(min(rem.front()->first, v[i].x1), max(rem.back()->second, v[i].x2));
			for (auto &x : rem) { seg.erase(x); }
			seg.insert(newR); p %= mod; res = (res * p) % mod;
		}

		ofs << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}