#include <iostream>
using namespace std;

long long sum(long long n) {
	return n * (n + 1) / 2;
}

long long n, k;

long long find_e(long long low, long long high) {
	if (low == high) { return low; }
	long long mid = (low + high) / 2;
	long long x = sum(n - mid) - mid;
	if (x == k) { return mid; }
	if (x < k) { return find_e(low, mid - 1); }
	return find_e(mid + 1, high);
}

int main() {
	cin >> n >> k;
	cout << find_e(0, n) << endl;
	cin.ignore(2); return 0;
}