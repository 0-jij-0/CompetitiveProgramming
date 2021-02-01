#include <iostream>
#include <string>
using namespace std;

int rooms[10]; string s;

int main() {
	int n; cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			for (int i = 0; i < 10; i++) { if (!rooms[i]) { rooms[i] = 1; break; } }
		}
		else if (s[i] == 'R') {
			for (int i = 9; i >= 0; i--) { if (!rooms[i]) { rooms[i] = 1; break; } }
		}
		else { rooms[s[i] - '0'] = 0; }
	}
	for (int i = 0; i < 10; i++) { cout << rooms[i]; }
	cout << endl; cin.ignore(2); return 0;
}