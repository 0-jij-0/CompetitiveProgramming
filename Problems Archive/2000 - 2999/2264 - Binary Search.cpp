#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v; int n;

string binarySearch(int x) {
	int l = 0, r = n - 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		v[mid] < x ? l = mid + 1 : r = mid;
	}
	return v[l] == x ? "YES" : "NO";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k; cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;

	while (k--) {
		int x; cin >> x;
		cout << binarySearch(x) << '\n';
	}
}