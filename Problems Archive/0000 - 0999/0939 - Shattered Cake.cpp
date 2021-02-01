#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int w, n; cin >> w >> n; int res = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; res += a * b;
	}
	cout << res / w << '\n';
	cin.ignore(2); return 0;
}