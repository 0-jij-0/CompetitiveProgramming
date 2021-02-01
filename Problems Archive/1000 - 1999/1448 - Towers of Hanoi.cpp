#include <iostream>
using namespace std;

void Hanoi(int start, int mid, int end, int n) {
	if (n == 1) { cout << start << ' ' << end << '\n'; return; }

	Hanoi(start, end, mid, n - 1);
	cout << start << ' ' << end << '\n';
	Hanoi(mid, start, end, n - 1);
}

int main() {
	int n; cin >> n;
	cout << (1 << n) - 1 << '\n';
	Hanoi(1, 2, 3, n);
	cin.ignore(2); return 0;
}