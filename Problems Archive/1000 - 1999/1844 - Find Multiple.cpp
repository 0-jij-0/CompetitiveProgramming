#include <iostream>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	int x = (a + c - 1) / c;
	cout << (x * c <= b ? x * c : -1) << '\n';
}