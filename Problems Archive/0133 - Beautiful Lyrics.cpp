#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct compare {
	bool operator ()(const string &s1, const string &s2) {
		if (s1.size() != s2.size()) { return s1.size() < s2.size(); }
		return s1 < s2;
	}
};

multimap<string, string, compare> m;
vector<string> words;
vector<char> vowels;

void beautiful_lyrics() {
	for (unsigned int i = 0; i < words.size(); i++) {
		string &s = words[i]; string str = "";
		for (int j = s.size() - 1; j >= 0; j--) {
			if (!binary_search(vowels.begin(), vowels.end(), s[j])) { continue; }
			str.push_back(s[j]);
		}
		pair<string, string> p(str, s);	m.insert(p);
	}
	vector<pair<string, string>> first, second;
	multimap<string, string, compare>::iterator it1 = m.begin();
	multimap<string, string, compare>::iterator it2 = it1; it2++;
	while (it2 != m.end()) {
		if (it1->first.size() != it2->first.size()) { it1++; it2++; continue; }
		if (it1->first.empty()) { it1++; it2++; continue; }
		if (it1->first[0] == it2->first[0]) {
			pair<string, string> p(it1->second, it2->second);
			second.push_back(p);
			it2 = m.erase(it2); it1 = m.erase(it1); if (it2 != m.end()) { it2++; }
			continue;
		}
		it1++; it2++;
	}
	it1 = m.begin(); it2 = it1; if (it2 != m.end()) { it2++; }
	while (it2 != m.end()) {
		if (it1->first.size() != it2->first.size()) { it1++; it2++; continue; }
		pair<string, string> p(it1->second, it2->second);
		first.push_back(p);
		it2 = m.erase(it2); it1 = m.erase(it1); if (it2 != m.end()) { it2++; }
		continue;
	}

	while (first.size() < second.size()) {
		first.push_back(second.back()); second.pop_back();
	}
	cout << second.size() << endl;
	for (unsigned int i = 0; i < second.size(); i++) {
		cout << first[i].first << " " << second[i].first << endl;
		cout << first[i].second << " " << second[i].second << endl;
	}
}

int main() {
	vowels.push_back('a'); vowels.push_back('e');
	vowels.push_back('i'); vowels.push_back('o');
	vowels.push_back('u');
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s; words.push_back(s);
	}
	if (n < 4) { cout << 0 << endl; }
	else { beautiful_lyrics(); }
	cin.ignore(2); return 0;
}
