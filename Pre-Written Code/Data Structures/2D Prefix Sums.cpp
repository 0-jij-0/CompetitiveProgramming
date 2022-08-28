#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct PrefSum2D {
	vector<vector<ll>> pref; int n; PrefSum2D() {}
	PrefSum2D(vector<vector<ll>> &_v) : n(_v.size()), pref(_v) {
		for (int j = 1; j < n; j++) { pref[0][j] += pref[0][j - 1]; }
		for (int i = 1; i < n; i++) { pref[i][0] += pref[i - 1][0]; }
		for (int i = 1; i < n; i++)	for (int j = 1; j < n; j++)
				pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
	}
	ll query(int xTL, int yTL, int xBR, int yBR) {
		ll res = pref[xBR][yBR];
		if (xTL) { res -= pref[xTL - 1][yBR]; }
		if (yTL) { res -= pref[xBR][yTL - 1]; }
		if (xTL && yTL) { res += pref[xTL - 1][yTL - 1]; }
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}