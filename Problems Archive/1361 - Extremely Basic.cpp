#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream ifs("hello.in");

	int t; ifs >> t; while (t--) {
		int x, y; ifs >> x >> y;
		cout << "sum = " << x + y << '\n';
	}
	ifs.close(); return 0;
}