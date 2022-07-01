#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v, a;

int main() {
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; v.resize(n);
		for (auto& x : v) cin >> x;
		string res(m, 'a'); a.resize(n - 1);
		for (auto& x : a) cin >> x;

		for (int i = 0; i < m; i++) {
			vector<int> freq(26, 0);
			for (auto& x : v) freq[x[i] - 'a']++;
			for (auto& x : a) freq[x[i] - 'a']--;
			res[i] += find(freq.begin(), freq.end(), 1) - freq.begin();
		}

		cout << res << endl;
	}
}