#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> b, g;
int n, m;

long long min_sweets() {
	long long count = 0;
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	count += b[n-1];

	int size = 1;
	if (g[0] == b[n-1]) { g.erase(g.begin()); size = 0; }
	while (g.size() != size) { count += g.back(); g.pop_back(); }

	if (size == 1) { count += g[0]; g.pop_back(); count += b[n - 2] * (m - 1); }
	else { count +=  b[n - 2] * m; }

	for (int i = n - 3; i >= 0; i--) { count += b[i] * m; }
	return count;	
}

int main() {
	cin >> n >> m;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; b.push_back(a);
		if (a > max) { max = a; }
	}
	int min = max;
	for (int i = 0; i < m; i++) {
		int a; cin >> a; g.push_back(a);
		if (a < min) { min = a; }
	}
	if (min < max) { cout << -1 << endl; }
	else { cout << min_sweets() << endl; }
	return 0;
}
