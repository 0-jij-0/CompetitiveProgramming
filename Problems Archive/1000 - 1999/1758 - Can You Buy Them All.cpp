#include <iostream>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	x += n/2; while (n--) {
		int s; cin >> s; x -= s;
	}
	cout << (x < 0 ? "No" : "Yes") << '\n';
}