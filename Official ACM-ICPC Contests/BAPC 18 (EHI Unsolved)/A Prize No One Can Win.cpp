#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, x; cin >> n >> x; v.resize(n);
	for (auto &a : v) { cin >> a; }
	sort(v.begin(), v.end());
	int max = 0, count = 0;
	for (auto &a : v) {
		if (a + max > x) { break; }
		count++; max = a;
	}
	cout << count << endl;
	cin.ignore(2); return 0;
}