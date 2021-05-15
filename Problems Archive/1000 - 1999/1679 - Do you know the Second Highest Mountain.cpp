#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int, string>> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) cin >> x.second >> x.first;
	sort(v.rbegin(), v.rend());
	cout << v[1].second << '\n';
	cin.ignore(2); return 0;
}