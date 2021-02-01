#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> score;

int main() {
	int n; cin >> n;
	while (n--) { string s; cin >> s; score[s]++; }
	cout << (score.rbegin()->second > score.begin()->second ? score.rbegin()->first : score.begin()->first) << endl;
	cin.ignore(2); return 0;
}