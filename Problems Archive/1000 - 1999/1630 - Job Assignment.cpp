#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b, s;

int main() {
	int n; cin >> n; s.resize(n);
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		s[i] = a[i] + b[i];
	}
	int res = *min_element(s.begin(), s.end());

	auto a1 = min_element(a.begin(), a.end());
	int temp = *a1; *a1 = 1 << 30;
	auto a2 = min_element(a.begin(), a.end());
	*a1 = temp;

	auto b1 = min_element(b.begin(), b.end());
	temp = *b1; *b1 = 1 << 30;
	auto b2 = min_element(b.begin(), b.end());
	*b1 = temp;

	if (a1 - a.begin() != b1 - b.begin()) { res = min(res, max(*a1, *b1)); }
	else { res = min({ res, max(*a1, *b2), max(*a2, *b1) }); }
	cout << res << '\n'; cin.ignore(2); return 0;
}