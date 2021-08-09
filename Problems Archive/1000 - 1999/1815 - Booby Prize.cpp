#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	*max_element(v.begin(), v.end()) = 0;
	cout << max_element(v.begin(), v.end()) - v.begin() + 1 << '\n';
	cin.ignore(2); return 0;
}