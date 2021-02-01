#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll w, h, n; cin >> w >> h >> n;
		ll W = 1, H = 1;
		while ((w & 1) == 0) { W <<= 1; w >>= 1; }
		while ((h & 1) == 0) { H <<= 1; h >>= 1; }
		cout << (W * H >= n ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}