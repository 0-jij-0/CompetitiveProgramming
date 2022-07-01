#include <iostream>
using namespace std;

int squares[4] = { 4, 9, 25, 49 };
int primes[15] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool query(int x) {
	if (x == 0) { cout << "composite" << endl; return 0; }
	if (x == 1) { cout << "prime" << endl; return 0; }
	cout << x << endl; string s; cin >> s;
	return s == "yes";
}

int main() {
	bool comp = false; int d = 0;
	for (int x : squares) comp |= query(x);
	for (int x : primes) d += query(x);
	query(!comp && d < 2);
}