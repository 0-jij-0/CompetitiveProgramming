#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
using namespace std;
typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

struct Slope {
	ll dx, dy; Slope() {}
	Slope(int _dx, int _dy) {
		if (_dx == 0) { dy = 1; dx = 0; }
		else {
			int g = gcd(abs(_dx), abs(_dy));
			dx = _dx / g; dy = _dy / g;
		}
	}

	bool operator < (const Slope & rhs) const {
		return (dy * rhs.dx) < (rhs.dy * dx);
	}
};

struct Building {
	ll x, y; int h; Building() {}
	Building(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
	bool operator < (const Building &rhs) const {
		ll a = x * x + y * y;
		ll b = rhs.x * rhs.x + rhs.y*rhs.y;
		return a < b;
	}
};

array<map<Slope, vector<Building>>, 2> buildings;

int main() {
	freopen("jaguar.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		buildings[0].clear(); buildings[1].clear();
		int n, X, Y; cin >> n >> X >> Y;
		for (int i = 0; i < n; i++) {
			int x, y, h; cin >> x >> y >> h;
			x -= X; y -= Y;	bool b = (x < 0) || (x == 0 && y < 0);
			buildings[!b][Slope(x, y)].emplace_back(x, y, h);
		}

		int res = 0; for (int i = 0; i < 2; i++)
			for (auto &s : buildings[i]) {
				sort(s.second.begin(), s.second.end());
				int H = 0; for (auto &b : s.second)
					if (b.h > H) { res++; H = b.h; }
			}

		cout << res << '\n';
	}
}