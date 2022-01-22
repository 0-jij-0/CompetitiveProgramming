#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) cin >> x;

	int cur = v[0];
	for (int i = 1; i < n; cur = v[i++])
		if (v[i] <= cur) break;

	cout << cur << '\n';
	cin.ignore(2); return 0;
}