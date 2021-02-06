#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> h;

int main() {
	int t; cin >> t; while (t--) {
		int n; ll k; cin >> n >> k; h.resize(n);
		for (auto& x : h) { cin >> x; }
		
		int i = 0, j = 1, res = -2; 
		while (j < n) {
			if (h[j] <= h[j - 1]) { i = j; j++; continue; }
			if (i == 0) {
				ll dif = h[j] - h[j - 1];
				if (dif * j < k) { 
					k -= dif * j; 
					for (int x = 0; x < j; x++) h[x] = h[j];
					j++; continue;
				}
				res = k % j == 0 ? 0 : j - (k % j); break;
			}
			if (h[i - 1] < h[j]) {
				ll dif = h[i - 1] - h[i];
				if (dif * (j - i) < k) {
					k -= dif * (j - i);
					for (int x = i; x < j; x++) h[x] = h[i - 1];
					while (i != 0 && h[i] == h[i - 1]) i--;
					continue;
				}
				int num = j - i;
				res = (k % num == 0) ? j - num : j - (k % num); break;
			}
			
			ll dif = h[j] - h[j - 1];
			if (dif * (j - i) < k) {
				k -= dif * (j - i);
				for (int x = i; x < j; x++) h[x] = h[j];
				j++; continue;
			}
			int num = (j - i);
			res = (k % num == 0) ? j - num : j - (k % num); break;
		}
		cout << res + 1 << '\n';
	}
	cin.ignore(2); return 0;
}