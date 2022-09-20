#include <iostream>
#include <vector>
using namespace std;

vector<int> v; int n;

int closestToTheLeft(int x) {
	int l = -1, r = n - 1;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		v[mid] > x ? r = mid - 1 : l = mid;
	}
	return l + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k; cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;

	while (k--) {
		int x; cin >> x;
		cout << closestToTheLeft(x) << '\n';
	}
}