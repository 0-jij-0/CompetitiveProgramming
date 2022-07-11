#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int p; cin >> s >> p; int n = (int)s.size();
		for (char c : s) p -= (c - 'a' + 1);
		p = max(0, -p);

		vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
		auto comp = [&](const int& i, const int& j) {return s[i] < s[j]; };
		sort(idx.begin(), idx.end(), comp);

		vector<int> keep(n, 1); 
		int i = n - 1; while (p > 0) {
			p -= (s[idx[i]] - 'a' + 1);
			keep[idx[i--]] = 0;
		}

		for (int i = 0; i < n; i++)
			if (keep[i]) cout << s[i];
		cout << '\n';
	}
}