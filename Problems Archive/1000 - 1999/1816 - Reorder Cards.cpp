#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> X, Y;

int main() {
	int h, w, n; cin >> h >> w >> n; v.resize(n);
	for (auto& x : v) {
		cin >> x.first >> x.second;
		X.push_back(x.first);
		Y.push_back(x.second);
	}
	sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for (auto& x : v) {
		cout << 1 + lower_bound(X.begin(), X.end(), x.first) - X.begin() << ' ';
		cout << 1 + lower_bound(Y.begin(), Y.end(), x.second) - Y.begin() << '\n';
	}

	cin.ignore(2); return 0;
}