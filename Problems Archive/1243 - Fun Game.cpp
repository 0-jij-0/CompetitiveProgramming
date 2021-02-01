#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> a, b;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; a.resize(n); b.resize(n);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }
		vector<int> v(n); iota(v.begin(), v.end(), 0);
		auto comp = [&](const int &i, const int &j) { return a[i] + b[i] < a[j] + b[j]; };
		sort(v.rbegin(), v.rend(), comp); int sA = 0, sB = 0;
		for (int i = 0; i < n; i++)	(i & 1 ? sB : sA) += (i & 1 ? b : a)[v[i]];
		if (sA == sB) { cout << "Tie" << '\n'; continue; }
		cout << (sA < sB ? "Second" : "First") << '\n';
	}
	cin.ignore(2); return 0;
}