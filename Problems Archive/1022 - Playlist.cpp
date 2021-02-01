#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> v; multiset<int> s;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int i = 0, j = 0, res =  0;
	while(j != n) {
		if (!s.count(v[j])) { s.insert(v[j++]); continue; }
		res = max(res, j - i);
		while (s.count(v[j])) { s.erase(s.find(v[i++])); }
	}
	cout << max(res, j - i) << endl;
	cin.ignore(2); return 0;
}