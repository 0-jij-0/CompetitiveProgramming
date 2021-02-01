#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int T; cin >> T; 
	for(int t = 1; t <= T; t++) {
		ll a, b, c; cin >> a >> b >> c;
		cout << "Case " << t << ": ";
		cout << a * (b * (b + 1) >> 1) * (c * (c + 1) >> 1) << '\n';
	}
	cin.ignore(2); return 0;
}