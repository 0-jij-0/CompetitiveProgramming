#include <iostream>
using namespace std;

void print_line(int D, int all) {
	if (all == 1) { cout << 'D'; return; }
	if (D == all) { cout << 'D'; print_line(D - 2, all - 2); cout << 'D'; return; }
	cout << '*'; print_line(D, all - 2); cout << '*';	
}

void print_diamond(int h, int w) {
	if (h == w) { print_line(w, w); cout << endl; return; }
	print_line(h, w); cout << endl;
	print_diamond(h + 2, w);
	print_line(h, w); cout << endl;
}

int main() {
	int n; cin >> n;
	print_diamond(1, n);
	cin.ignore(2); return 0;
}