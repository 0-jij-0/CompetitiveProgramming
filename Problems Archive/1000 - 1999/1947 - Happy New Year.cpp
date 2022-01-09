#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string kthSmallest(ll k) {
	string res = ""; while (k) {
		res.push_back('0' + 2 * (k & 1));
		k >>= 1;
	}
	reverse(res.begin(), res.end()); return move(res);
}

int main() {
	ll k; cin >> k;
	cout << kthSmallest(k) << '\n';
	cin.ignore(2); return 0;
}