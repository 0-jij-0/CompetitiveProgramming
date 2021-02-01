#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> m, f;

int main() {
	int n; cin >> n;
	m.resize(368, 0); f.resize(368, 0);
	for (int i = 0; i < n; i++) {
		char c; int a, b; cin >> c >> a >> b;
		(c == 'M' ? m : f)[a]++;
		(c == 'M' ? m : f)[b + 1]--;
	}
	partial_sum(m.begin(), m.end(), m.begin());
	partial_sum(f.begin(), f.end(), f.begin());
	int res = 0;
	for (int i = 1; i <= 366; i++)
		res = max(res, 2 * min(m[i], f[i]));
	cout << res << endl;
	cin.ignore(2); return 0;
}