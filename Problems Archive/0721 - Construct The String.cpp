#include <iostream>
#include <string>
using namespace std;

string str = "abcdefghijklmnopqrstuvwxyz";

int main() {
	int t; cin >> t;
	while (t--) {
		int n, a, b; cin >> n >> a >> b;
		string s = str.substr(0, b), res = "";
		while ((int)res.size() + b <= n) { res += s; }
		int rem = n - res.size(); res += s.substr(0, rem);
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}