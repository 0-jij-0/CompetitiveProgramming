#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s; m[s]++;
	}
	int res = 0;
	for (auto &x : m) { res = max(res, x.second); }
	cout << res << endl;
	cin.ignore(2); return 0;
}