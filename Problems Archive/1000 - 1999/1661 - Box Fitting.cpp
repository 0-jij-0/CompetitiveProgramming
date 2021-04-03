#include <iostream>
#include <vector>
using namespace std;

vector<int> freq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, w; cin >> n >> w;
		freq.clear(); freq.resize(30, 0);
		for (int i = 0; i < n; i++) {
			int w; cin >> w; int id = 0;
			while (w != 1) { id++; w >>= 1; }
			freq[id]++;
		}
		int res = 0, rem = n; while (rem) {
			res++; int remW = w, i = 29;
			while (i >= 0 && rem) {
				if (1 << i > remW) { i--; continue; }
				if (freq[i] == 0) { i--; continue; }
				int c = remW / (1 << i);
				int take = min(c, freq[i]);
				remW -= take * (1 << i); rem -= take;
				freq[i] -= take; i--;
			}
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}