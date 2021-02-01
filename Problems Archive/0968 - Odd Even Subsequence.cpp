#include <iostream>
#include <vector>
using namespace std;

vector<int> v; int n, k;

bool check(const int &m) {
	int idx = 0, i = 0;
	while (idx != (k + 1) / 2 && i < n - (k % 2 == 0)) {  //Even subsequence
		if (v[i] > m) { i++; continue; }
		i += 2; idx++;
	}
	if (idx == (k + 1) / 2) { return true; }
	idx = 0; i = 1;
	while (idx != k / 2 && i < n - (k % 2)) { //Odd Subsequence
		if (v[i] > m) { i++; continue; }
		i += 2; idx++;
	}
	return idx == (k / 2);
}

int findMinCost() {
	int l = 0, r = 1 << 30;
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	cin >> n >> k; v.resize(n);
	for (auto &x : v) { cin >> x; }
	cout << findMinCost() << '\n';
	cin.ignore(2); return 0;
}