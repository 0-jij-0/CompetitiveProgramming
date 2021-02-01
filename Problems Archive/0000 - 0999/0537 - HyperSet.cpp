#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k; cin >> n >> k;
	v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	int res = 0;
	for(int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++) {
			string &a = v[i], &b = v[j];
			string c(k, 'A');
			for (int x = 0; x < k; x++) {
				if (a[x] == b[x]) { c[x] = a[x]; continue; }
				if (a[x] != 'S' && b[x] != 'S') { c[x] = 'S'; }
				if (a[x] != 'E' && b[x] != 'E') { c[x] = 'E'; }
				if (a[x] != 'T' && b[x] != 'T') { c[x] = 'T'; }
			}
			res += binary_search(v.begin() + j + 1, v.end(), c);
		}
	cout << res << endl;
	cin.ignore(2); return 0;
}