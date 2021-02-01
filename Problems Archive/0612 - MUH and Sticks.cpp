#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(6);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());

	int l = 0, r = 1, len = 1;
	while (r < 6) {
		if (v[l] == v[r]) { len++; r++; }
		else { l = r; r++; len = 1; }
		if (len == 4) { break; }
	}
	if (len != 4) { cout << "Alien" << endl; }
	else {
		v.erase(v.begin() + l, v.begin() + r);
		cout << (v[0] == v[1] ? "Elephant" : "Bear") << endl;
	}
	cin.ignore(2); return 0;
}