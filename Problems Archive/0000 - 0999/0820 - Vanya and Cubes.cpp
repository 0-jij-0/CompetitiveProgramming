#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	v.resize(100); iota(v.begin(), v.end(), 0);
	partial_sum(v.begin(), v.end(), v.begin());
	partial_sum(v.begin(), v.end(), v.begin());
	int n; cin >> n;
	int idx = lower_bound(v.begin(), v.end(), n) - v.begin();
	cout << idx - (v[idx] != n) << endl;
	cin.ignore(2); return 0;
}