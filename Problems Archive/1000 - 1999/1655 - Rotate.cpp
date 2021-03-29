#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s; s.push_back(s[0]);
	s.erase(s.begin()); cout << s << '\n';
}