#include <iostream>
using namespace std;

int main() {
	int n, m, k; cin >> n >> m >> k;
	int min = (m < k) ? m : k;
	if (min < n) { cout << "No" << endl; }
	else { cout << "Yes" << endl; }
	cin.ignore(2); return 0;
}