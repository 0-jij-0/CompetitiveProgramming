#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	for (auto& x : v) { int y; cin >> y; x *= y; }

	cout << (accumulate(v.begin(), v.end(), 0ll) == 0 ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}