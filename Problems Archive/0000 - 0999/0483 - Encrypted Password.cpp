#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string encS, s; cin >> encS >> s;
	map<char, int> freq;
	int n1 = (int)s.size(), n2 = (int)encS.size();

	int stillNeeded = 0;
	for (int i = 0; i < n1; i++) {
		if (freq[s[i]] == 0) { stillNeeded++; }
		freq[s[i]]++;
	}

	for (int i = 0; i < n1; i++) {
		freq[encS[i]]--;
		if (freq[encS[i]] == 0) { stillNeeded--; }
	}
	for (int i = n1; i < n2; i++) {
		if (stillNeeded == 0) { break; }
		freq[encS[i - n1]]++;
		if (freq[encS[i - n1]] == 1) { stillNeeded++; }
		freq[encS[i]]--;
		if (freq[encS[i]] == 0) { stillNeeded--; }
		if (stillNeeded == 0) { break; }
	}

	cin.ignore(2); return 0;
}

