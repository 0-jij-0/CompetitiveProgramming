#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> tg;
string s;

string find_max() {
	string t = "";
	t.push_back(s[0]); t.push_back(s[1]);
	tg[t]++;
	for (unsigned int i = 2; i < s.size(); i++) {
		t.erase(t.begin()); t.push_back(s[i]);
		tg[t]++;
	}
	string max_tg = ""; int max = 0;
	map<string, int>::iterator it = tg.begin();
	for (; it != tg.end(); it++) {
		if (it->second > max) {
			max = it->second; max_tg = it->first;
		}
	}
	return max_tg;
}

int main() {
	int n; cin >> n;
	cin >> s;
	cout << find_max() << endl;
	cin.ignore(2); return 0;
}