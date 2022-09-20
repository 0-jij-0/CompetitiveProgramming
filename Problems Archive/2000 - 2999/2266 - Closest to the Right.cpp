#include <iostream>
#include <vector>
using namespace std;

vector<int> v; int n;

int closestToTheRight(int x) {
	int l = 0, r = n;
	while (l != r) {
		int mid = (l + r) >> 1;
		v[mid] < x ? l = mid + 1 : r = mid;
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
		cout << closestToTheRight(x) << '\n';
	}
}