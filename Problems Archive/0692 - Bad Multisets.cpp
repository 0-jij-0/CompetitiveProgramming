#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	if (N <= 2) { cout << N << endl; return 0; }
	long long ans = 2, prev = 2;
	for (int i = 2; i < N; i++) { ans += prev; prev <<= 1; }
	cout << ans << endl; cin.ignore(2); return 0;
}