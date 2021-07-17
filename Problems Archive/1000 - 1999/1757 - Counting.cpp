#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	cout << max(0, b - a + 1) << '\n';
}