#include <iostream>
#include <climits>
using namespace std;

int main() {
	long long x; cin >> x;
	cout << (x <= INT_MAX && x >= INT_MIN ? "Yes" : "No") << '\n';
}