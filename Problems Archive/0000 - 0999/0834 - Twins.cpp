#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.rbegin(), v.rend());
	int sum = accumulate(v.begin(), v.end(), 0);
	int mySum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		mySum += v[i]; sum -= v[i]; res++;
		if (mySum > sum) { break; }
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}