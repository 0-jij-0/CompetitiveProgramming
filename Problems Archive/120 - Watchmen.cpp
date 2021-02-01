#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
map<int, ll> X, Y;
map<pair<int, int>, ll> P;

int main() {
	int n; cin >> n; ll res = 0;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		res += X[x] + Y[y] - P[{x, y}];
		X[x]++; Y[y]++; P[{x, y}]++;
	}
	cout << res << endl; cin.ignore(2); return 0;
}