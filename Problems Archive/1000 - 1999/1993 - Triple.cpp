#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		vector<int> freq(n + 1); 
		for (auto& x : v) freq[x]++;
		auto ma = max_element(freq.begin(), freq.end());

		cout << (*ma > 2 ? ma - freq.begin() : -1) << '\n';
	}

	cin.ignore(2); return 0;
}