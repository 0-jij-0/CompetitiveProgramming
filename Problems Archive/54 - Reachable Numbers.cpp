#include <iostream>
#include <map>
using namespace std;

bool dig[10];

int f(int &n) {
	int res = n + 1;
	while (res % 10 == 0) { res = res / 10; }
	return res;
}

int reachable(int n) {
	int count = 1;
	if (n < 10) { dig[n] = true; }
	while (n > 10 || dig[f(n)] == false) {
		int x = f(n);
		if (x < 10) { dig[x] = true; }
		count++; n = x; 
	}
	return count;
}

int main() {
	int n; cin >> n;
	cout << reachable(n) << endl;
	cin.ignore(2); return 0;
}