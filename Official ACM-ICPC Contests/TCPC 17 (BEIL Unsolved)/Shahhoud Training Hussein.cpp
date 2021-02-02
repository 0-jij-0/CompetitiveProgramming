#include <iostream>
using namespace std;

int main() {
	int T; cin >> T;
	for (int z = 0; z < T; z++) {
		long long K, P, N; cin >> K >> P >> N;
		if (P >= K) { cout << 0 << endl; }
		else { cout << (K - P)*N << endl; }
	}
	cin.ignore(2); return 0;
}