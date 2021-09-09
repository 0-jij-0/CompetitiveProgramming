#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; x--; }

	vector<int> res(n);
	for (int i = 0; i < n; i++) res[v[i]] = i;
	for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	cin.ignore(2); return 0;
}