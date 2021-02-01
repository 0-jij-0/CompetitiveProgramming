#include <iostream>
using namespace std;

int main() {
	long long n; cin >> n;
	cout << (((n * (n + 1)) >> 1) & 1);
}