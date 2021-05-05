#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	for (int l = 1; l < 10; l++) {
		for (int i = 1; i < 10; i++) {
			string s(l, i + '0');
			v.push_back(stoi(s));
		}
	}

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		auto it = upper_bound(v.begin(), v.end(), n);
		cout << it - v.begin() << '\n';
	}

	cin.ignore(2); return 0;
}