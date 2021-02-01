#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;
int n, m, ta, tb, k;

int maximin_time() {
	if (k >= n || k >= m) { return -1; }
	int max = 0;
	for (int i = 0; i <= k; i++) {
		int kl = k - i;
		int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (idx + kl >= m) { return -1; }
		max = (max > b[idx + kl]) ? max : b[idx + kl];
	}
	return max + tb;
}

int main() {
	cin >> n >> m >> ta >> tb >> k;
	a.resize(n); b.resize(m);
	for (int i = 0; i < n; i++) { cin >> a[i]; a[i] += ta; }
	for (int i = 0; i < m; i++) { cin >> b[i]; }
	cout << maximin_time() << endl;
	cin.ignore(2); return 0;
}