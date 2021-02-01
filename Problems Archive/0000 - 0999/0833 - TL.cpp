#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, w;

int main() {
	int n, m; cin >> n >> m;
	a.resize(n); w.resize(m);
	for (auto &x : a) { cin >> x; }
	for (auto &x : w) { cin >> x; }
	int tl = *min_element(w.begin(), w.end()) - 1;
	int ex = *min_element(a.begin(), a.end());
	int lb = *max_element(a.begin(), a.end());
	if (lb > tl) { cout << -1 << endl; }
	else if (2 * ex > tl) { cout << -1 << endl; }
	else { cout << max(2 * ex, lb) << endl; }
	cin.ignore(2); return 0;
}