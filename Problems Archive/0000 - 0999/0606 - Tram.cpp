#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) {
		int a, b; cin >> a >> b;
		x = b - a;
	}
	partial_sum(v.begin(), v.end(), v.begin());
	cout << *max_element(v.begin(), v.end()) << endl;
	cin.ignore(2); return 0;
}