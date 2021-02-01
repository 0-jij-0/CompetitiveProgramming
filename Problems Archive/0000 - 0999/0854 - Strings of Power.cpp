#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	string s; cin >> s;
	ll ans = 0, h = 0; int n = (int)s.size();
	for (int i = 0; i < n - 4; i++) {
		string str = s.substr(i, 5);
		if (str == "heavy") { h++; continue; }
		if (str == "metal") { ans += h; continue; }
	}
	cout << ans << endl;
	cin.ignore(2); return 0;
}