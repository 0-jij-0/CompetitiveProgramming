#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> v;

int main() {
	int t; cin >> t; v.resize(9);
	while (t--) {
		for (auto &x : v) { cin >> x; x[find(x.begin(), x.end(), '1') - x.begin()] = '2'; }
		for (auto &x : v) { cout << x << '\n'; }
	}
	cin.ignore(2); return 0;
}