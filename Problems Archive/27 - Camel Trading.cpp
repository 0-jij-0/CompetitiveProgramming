#include <iostream>
#include <string>
using namespace std;

unsigned long long recMin(string s) {
	int i = s.find('+');
	if (i != s.npos) {
		string a = s.substr(0, i);
		string b = s.substr(i + 1);
		return recMin(a) + recMin(b);
	}
	i = s.find('*');
	if (i != s.npos) {
		string a = s.substr(0, i);
		string b = s.substr(i + 1);
		return recMin(a) * recMin(b);
	}
	return stoi(s);
}
unsigned long long recMax(string s) {
	int i = s.find('*');
	if (i != s.npos) {
		string a = s.substr(0, i);
		string b = s.substr(i + 1);
		return recMax(a) * recMax(b);
	}
	i = s.find('+');
	if (i != s.npos) {
		string a = s.substr(0, i);
		string b = s.substr(i + 1);
		return recMax(a) + recMax(b);
	}
	return stoi(s);
}

void camelTrading(string s) {
	unsigned long long min = recMin(s);
	unsigned long long max = recMax(s);
	cout << "The maximum and minimum are " << max << " and " << min << "." << endl;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		camelTrading(s);
	}
	cout << endl; cin.ignore(2); return 0;
}
