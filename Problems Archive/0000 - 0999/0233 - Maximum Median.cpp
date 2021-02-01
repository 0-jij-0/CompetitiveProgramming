#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, k;

int find_min() {
	int min = v.front(); int i = 1;
	while (k != 0 && i < (int)v.size()) {
		int dif = v[i] - v[i - 1];
		if (k >= (long long) i * dif) { 
			min += dif; k -= i * dif;
			i++; continue;
		}
		else { break; }
	}
	return min + (k / i);
}

int main() {
	cin >> n >> k; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < n / 2; i++) { v.pop_back(); }
	reverse(v.begin(), v.end());
	cout << find_min() << endl;
	cin.ignore(2); return 0;
}