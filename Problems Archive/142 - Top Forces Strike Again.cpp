#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int max_prettiness(int n) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	n = (int)v.size(); int ans = v.back();

	for (int i = n - 1; i >= 0 && v[i] + v[i - 1] > ans; i--) {
		for (int j = i - 1; j >= 0 && v[i] + v[j] > ans; --j) {
			if (v[i] % v[j]) { ans = v[i] + v[j]; break; }
		}
	}

	for (int i = n - 1; i >= 2 && v[i] + v[i - 1] + v[i - 2] > ans; i--) {
		for (int j = i - 1; j >= 1 && v[i] + v[j] + v[j - 1] > ans; j--) {
			if (v[i] % v[j]) {
				for (int k = j - 1; k >= 0 && v[i] + v[j] + v[k] > ans; k--) {
					if (v[i] % v[k] && v[j] % v[k]) { ans = v[i] + v[j] + v[k]; break; }
				}
			}
		}
	}
	return ans;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n; cin >> n;
		v.clear(); v.resize(n);
		for (int j = 0; j < n; j++) { cin >> v[j]; }
		cout << max_prettiness(n) << endl;
	}
	cin.ignore(2); return 0;
}