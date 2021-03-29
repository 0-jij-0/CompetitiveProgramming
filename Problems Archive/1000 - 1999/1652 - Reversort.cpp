#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; 
	for(int t = 1; t <= T; t++) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		int cost = 0; for (int i = 0; i < n - 1; i++) {
			auto it = min_element(v.begin() + i, v.end());
			cost += it - v.begin() - i + 1;
			reverse(v.begin() + i, it + 1);
		}
		cout << "Case #" << t << ": " << cost << '\n';
	}
	cin.ignore(2); return 0;
}