#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; int sum = 0; v.resize(n);
	for (auto &x : v) { cin >> x; sum += x; }
	sort(v.begin(), v.end());
	int left = sum / n, right = (sum + n - 1) / n, count = sum % n;
	int res = 0;
	for (int i = n - 1; i >= n - count; i--) { res += abs(right - v[i]); }
	for (int i = 0; i < n - count; i++) { res += abs(left - v[i]); }
	cout << res / 2 << endl;
	cin.ignore(2); return 0;
}