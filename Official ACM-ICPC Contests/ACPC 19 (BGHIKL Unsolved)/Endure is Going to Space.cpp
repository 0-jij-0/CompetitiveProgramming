#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	freopen("endure.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string a; ll y, s; 
		cin >> a >> y >> s;
		y *= 365 * 24 * 3600;
		cout << y * s << '\n';
	}
}