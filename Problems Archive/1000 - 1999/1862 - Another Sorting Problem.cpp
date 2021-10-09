#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

bool compare(string& s, string& t) {
	int n = (int)s.size();
	for (int i = 0; i < n; i += 2) {
		if (s[i] < t[i]) { return true; }
		if (s[i] > t[i]) { return false; }
		if (i + 1 == n) { break; }
		if (s[i + 1] > t[i + 1]) { return true; }
		if (s[i + 1] < t[i + 1]) { return false; }
	}
	return false;
}

vector<string> v;
vector<int> idx;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto& x : v) { cin >> x; }
	idx.resize(n); iota(idx.begin(), idx.end(), 0);
	auto comp = [&](const int& i, const int& j) { return compare(v[i], v[j]); };
	sort(idx.begin(), idx.end(), comp);
	for (auto& x : idx) cout << ++x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}