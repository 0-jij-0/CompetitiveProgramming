#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n, m; cin >> n >> m; v.resize(m);
	for (auto &x : v) { cin >> x.first >> x.second; }
	for (auto &x : v) {
		if (x.first > x.second) swap(x.first, x.second);
		cout << x.first << ' ' << x.second << '\n';
	}
	cin.ignore(2); return 0;
}