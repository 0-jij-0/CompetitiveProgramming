#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x.first >> x.second; }

	int res = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			res += abs((v[i].second - v[j].second + 0.0) / (v[i].first - v[j].first + 0.0)) <= 1.0;

	cout << res << '\n';
	cin.ignore(2); return 0;
}