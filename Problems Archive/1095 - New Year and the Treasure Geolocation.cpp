#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<int, int>> ab, xy;

int main() {
	int n; cin >> n; ab.resize(n); xy.resize(n);
	for (auto &x : xy) { cin >> x.first >> x.second; }
	for (auto &x : ab) { cin >> x.first >> x.second; }
	ll X = 0, Y = 0; for (int i = 0; i < n; i++) {
		X += xy[i].first + ab[i].first;
		Y += xy[i].second + ab[i].second;
	}
	cout << X / n << ' ' << Y / n << endl;
	cin.ignore(2); return 0;
}