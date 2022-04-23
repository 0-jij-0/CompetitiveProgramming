#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool setAllBits(int i, int &k) {
	int res = 0; for(auto &x : v)
		if (!(x & (1 << i))) { res++; }
	if (res > k) { return false; }
	k -= res; return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; }

		int gain = 0; for(int i = 30; i >= 0; i--)
			if (setAllBits(i, k)) { gain |= 1 << i; }

		int bitAND = v[0]; for (auto& x : v) bitAND &= x;
		cout << (gain | bitAND) << '\n';
	}
	
	cin.ignore(2); return 0;
}

