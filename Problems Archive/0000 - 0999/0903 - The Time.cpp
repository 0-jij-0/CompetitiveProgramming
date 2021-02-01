#include <iostream>
using namespace std;

int main() {
	int h, m, a; char C; 
	cin >> h >> C >> m >> a;
	a %= 1440; int ma = a % 60, ha = a / 60;
	int M = (m + ma) % 60, c = (m + ma) / 60;
	int H = (h + ha + c) % 24;
	if (H < 10) { cout << 0 << H << ':'; }
	else { cout << H << ':'; }
	if (M < 10) { cout << 0 << M << '\n'; }
	else { cout << M << '\n'; }
	cin.ignore(2); return 0;
}