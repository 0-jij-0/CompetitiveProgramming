#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(1 << n);
	for (auto& x : v) { cin >> x; }
	int h = 1 << (n - 1);
	int w1 = max_element(v.begin(), v.begin() + h) - v.begin();
	int w2 = max_element(v.begin() + h, v.end()) - v.begin();
	cout << (v[w1] < v[w2] ? w1 : w2) + 1 << '\n';
	cin.ignore(2); return 0;
}