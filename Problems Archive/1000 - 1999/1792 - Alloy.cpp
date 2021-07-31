#include <iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	cout << (a && b ? "Alloy" : a ? "Gold" : "Silver");
}