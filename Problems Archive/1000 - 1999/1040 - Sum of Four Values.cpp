#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int n, x; cin >> n >> x; v.resize(n);
	for (auto &x : v) { cin >> x; }
	
	map<int, pair<int, int>> before;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int rem = x - v[i] - v[j];
			if (before.count(rem)) {
				cout << before[rem].first << ' ' << before[rem].second
					<< ' ' << i + 1 << ' ' << j + 1 << '\n';
				cin.ignore(2); return 0;
			}
		}
		for (int j = 0; j < i; j++)
			before[v[j] + v[i]] = { j + 1, i + 1 };
	}
	cout << "IMPOSSIBLE" << endl;
	cin.ignore(2); return 0;
}