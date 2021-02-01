#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct rect {
	ll x1, x2, h; rect() {}
	rect(ll _x1, ll _x2, ll _h) : x1(_x1), x2(_x2), h(_h) {}
};

ll W; vector<rect> v;

int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");

	int T; ifs >> T; 
	for (int t = 1; t <= T; t++) {
		int n, k; ifs >> n >> k >> W; v.resize(n);
		for (int i = 0; i < k; i++) ifs >> v[i].x1;
		ll AL, BL, CL, DL; ifs >> AL >> BL >> CL >> DL;
		for (int i = 0; i < k; i++) ifs >> v[i].h;
		ll AH, BH, CH, DH; ifs >> AH >> BH >> CH >> DH;
		for (int i = k; i < n; i++) {
			v[i].x1 = 1 + ((v[i - 2].x1 * AL + v[i - 1].x1 * BL + CL) % DL);
			v[i].h = 1 + ((v[i - 2].h * AH + v[i - 1].h * BH + CH) % DH);
		}
		
		ll res = 1, add = 0; int curL = -1;
		ll ups = 0, downs = 0; vector<rect> dq;
		for (int i = 0; i < n; i++) {
			if (dq.empty()) {
				curL = i; ups = downs = 0;
				dq.emplace_back(v[i].x1, v[i].x1 + W, v[i].h);
				ll p = 2 * (W + v[i].h); p %= mod;
				p = (p + add) % mod; res = (res * p) % mod;
				continue;
			}
			if (i && v[i].x1 > v[i - 1].x1 + W) {
				add += 2 * (v[i - 1].x1 + W - v[curL].x1) + v[curL].h + v[i - 1].h + ups + downs; add %= mod;
				dq.clear(); curL = i; ups = downs = 0; ll p = 2 * (W + v[i].h); p %= mod;
				p = (p + add) % mod; res = (res * p) % mod; dq.emplace_back(v[i].x1, v[i].x1 + W, v[i].h);
				continue;
			}
			while (v[i].h > dq.back().h && v[i].x1 <= dq.back().x1) {
				rect R = dq.back(); dq.pop_back(); downs -= dq.back().h - R.h;
			}
			if (v[i].h <= dq.back().h) {
				downs += dq.back().h - v[i].h;
				dq.emplace_back(dq.back().x2, v[i].x1 + W, v[i].h);
				ll p = 2 * (v[i].x1 + W - v[curL].x1) + v[i].h + v[curL].h + ups + downs;
				p = (p + add) % mod; res = (res * p) % mod; continue;
			}
			ups += v[i].h - dq.back().h; dq.emplace_back(v[i].x1, v[i].x1 + W, v[i].h);
			ll p = 2 * (v[i].x1 + W - v[curL].x1) + v[i].h + v[curL].h + ups + downs;
			p = (p + add) % mod; res = (res * p) % mod;
		}
		ofs << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}