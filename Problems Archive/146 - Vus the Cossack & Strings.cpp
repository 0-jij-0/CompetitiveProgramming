#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a, b;
vector<int> ones;

int main() {
	cin >> a >> b; ones.resize(a.size() + 1);
	int b1 = 0, a1 = 0;
	for (unsigned int i = 0; i < b.size(); i++) {
		if (b[i] == '1') { b1++; }
	}
	for (unsigned int i = 0; i <= a.size(); i++) {
		ones[i] = a1; if (a[i] == '1') { a1++; }
	}
	int count = 0;
	for (unsigned int i = b.size(); i <= a.size(); i++) {
		if (b1 % 2 == (ones[i] - ones[i - b.size()]) % 2) { count++; }
	}
	cout << count << endl;
	cin.ignore(2); return 0;
}