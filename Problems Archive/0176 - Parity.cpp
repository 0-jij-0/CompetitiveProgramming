#include <iostream>
using namespace std;

int main() {
	int b, k; cin >> b >> k;
	int o = 0; int a;
	for (int i = 0; i < k; i++) { 
		cin >> a; if (a % 2) { o++; }
	}
	bool bo = false;
	if (b % 2) { bo = o % 2; }
	else { bo = a % 2; }
	if (!bo) { cout << "Even" << endl; }
	else { cout << "Odd" << endl; }
	cin.ignore(2); return 0;
}