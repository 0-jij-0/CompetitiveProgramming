#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; p.resize(n - 1);
	for (auto& x : p) { cin >> x; x--; }

	int cur = n - 2, res = 0;
	while (cur >= 0) { res++; cur = p[cur] - 1; }
	cout << res << '\n';
}