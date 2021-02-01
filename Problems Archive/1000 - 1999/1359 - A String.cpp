#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream ifs("string.in");
	
	int t; ifs >> t; while (t--) {
		string s; ifs >> s; cout << s << '\n';
	}
	ifs.close(); return 0;
}