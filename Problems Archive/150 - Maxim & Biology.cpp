#include <iostream>
#include <string>
using namespace std;

string s;

int dist(int a, int b) {
	if (a < b) {
		int m1 = b - a;
		int m2 = 26 + a - b;
		return (m1 < m2) ? m1 : m2;
	}
	int m1 = a - b;
	int m2 = 26 + b - a;
	return (m1 < m2) ? m1 : m2;
}

int count_op(int i) {
	int a = dist(s[i] - 'A', 'A' - 'A');
	int b = dist(s[i + 1] - 'A', 'C' - 'A');
	int c = dist(s[i + 2] - 'A', 'T' - 'A');
	int d = dist(s[i + 3] - 'A', 'G' - 'A');
	return a + b + c + d;
}

int min_op() {
	int min = 4 * 26;;
	for (unsigned int i = 0; i < s.size() - 3; i++) {
		int a = count_op(i);
		if (a < min) { min = a; }
	}
	return min;
}

int main(){
	int n; cin >> n >> s;
	cout << min_op() << endl;
	cin.ignore(2); return 0;
}