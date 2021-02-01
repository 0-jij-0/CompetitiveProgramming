#include <iostream>
using namespace std;

int main() {
	int m, n; cin >> m >> n;
	int count = 0;
	if (m % 2 == 0 || n % 2 == 0) { count = n * m / 2; }
	else if(m == 1 && n == 1){}
	else { 
		int x = (m == 1) ? n : m;
		int y = (m == 1) ? m : n;
		count = (x - 1)*y / 2;
		count += y / 2;
	}
	cout << count << endl;
	cin.ignore(2); return 0;
}