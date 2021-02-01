#include <iostream>
#include <cmath>
using namespace std;

void towersOfHanoi(int n, char from, char to, char mid) {

	if (n == 1) { cout << "move disk 1 from tower " << from << " to tower " << to << endl; return; }

	towersOfHanoi(n - 1, from, mid, to);

	cout << "move disk "<< n << " from tower " << from << " to tower " << to << endl;

	towersOfHanoi(n - 1, mid, to, from);
}

void recKth(int n, int k, char from, char to, char mid) {

	int m = pow(2.0, n - 1.0);
	if      (k > m) { recKth(n - 1, k - m, mid, to, from); }
	else if (k < m) { recKth(n - 1, k, from, mid, to); }
	else { cout << "move from " << from << " to " << to << endl; }

}

void kThHanoi(int n, int k, char from, char to, char mid) {
	double m = pow(2.0, n + 0.0) - 1;
	if (n > m) { cout << "no such move"; return; }

	recKth(n, k, from, to, mid);
}


int main() {

	towersOfHanoi(5, 'A', 'C', 'B');
	cout << endl;
	kThHanoi(4, 12, 'A', 'C', 'B');

	cin.ignore(2);
	return 0;
}