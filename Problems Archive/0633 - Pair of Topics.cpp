#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;
vector<int> dif;

int main() {
	int n; cin >> n; a.resize(n); b.resize(n);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }
	for (int i = 0; i < n; i++) 
		dif.push_back(a[i] - b[i]);

	sort(dif.begin(), dif.end());
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int d = a[i] - b[i];
		int req = 1 - d;
		int idx = lower_bound(dif.begin(), dif.end(), req) - dif.begin();
		res += n - idx; if (d >= req) { res--; }
	}
	cout << res / 2 << endl; cin.ignore(2); return 0;
}