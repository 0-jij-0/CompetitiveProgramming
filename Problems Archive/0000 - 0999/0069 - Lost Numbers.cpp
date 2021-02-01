#include <iostream>
#include <cstdio>
using namespace std;

int a1, a2, a3, a4, a5, a6;
int special[6] = { 42, 23, 16, 15, 8, 4 };

void check1(int a, int b) {
	for (int i = 0; i < 6; i++) {
		if (a % special[i] == 0 && b % special[i] == 0) {
			int x = a / special[i]; int y = b / special[i];
			if (x == special[i] || y == special[i]) { continue; }
			if ((x == 42 || x == 23 || x == 16 || x == 15 || x == 8 || x == 4) && (y == 42 || y == 23 || y == 16 || y == 15 || y == 8 || y == 4)) {
				a1 = special[i]; break;
			}
			continue;
		}
	}
	a2 = a / a1; a3 = b / a1;
}
void check2(int a, int b) {
	for (int i = 0; i < 6; i++) {
		if (a % special[i] == 0 && b % special[i] == 0) {
			int x = a / special[i]; int y = b / special[i];
			if (x == special[i] || y == special[i]) { continue; }
			if ((x == 42 || x == 23 || x == 16 || x == 15 || x == 8 || x == 4) && (y == 42 || y == 23 || y == 16 || y == 15 || y == 8 || y == 4)) {
				a4 = special[i]; break;
			}
			continue;
		}
	}
	a5 = a / a4; a6 = b / a4;
}

int main() {
	int i = 0;
	int response[2];

	cout << "? 1 2" << endl;
	fflush(stdout);
	cin >> response[0];

	cout << "? 1 3" << endl;
	fflush(stdout);
	cin >> response[1];

	check1(response[0], response[1]);

	cout << "? 4 5" << endl;
	fflush(stdout);
	cin >> response[0];

	cout << "? 4 6" << endl;
	fflush(stdout);
	cin >> response[1];

	check2(response[0], response[1]);

	cout << "! " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;
	fflush(stdout);
	return 0;
}