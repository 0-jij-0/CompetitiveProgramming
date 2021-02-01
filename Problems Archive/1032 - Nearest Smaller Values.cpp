#include <iostream>
#include <vector>
using namespace std;

vector<int> v, res;

int main() {
	int n; cin >> n; v.resize(n); res.resize(n);
	for (auto &x : v) { cin >> x; }
	res.front() = -1; int i = 1;
	while (i < n) {
		int j = i - 1;
		while (j != -1 && v[j] >= v[i]) { j = res[j]; }
		res[i++] = j;
	}
	for (auto &x : res) { cout << x + 1 << ' '; }
	cout << '\n'; cin.ignore(2); return 0;
}