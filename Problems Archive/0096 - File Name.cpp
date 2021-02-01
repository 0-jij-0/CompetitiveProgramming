#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;

int delete_count() {
	int consx = 0, count = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] != 'x') { consx = 0; continue; }
		if (consx != 2) { consx++; continue; }
		count++;
	}
	return count;
}

int main() {
	int n; cin >> n;
	cin >> s;
	cout << delete_count() << endl;
	cin.ignore(2); return 0;
}