#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string s;
vector<int> freq;
deque<int> odd;

int main() {
	cin >> s; freq.resize(26);
	for (char c : s) { freq[c - 'a']++; }
	for (int i = 0; i < 26; i++) {
		if (freq[i] % 2 == 0) { continue; }
		odd.push_back(i);
	}
	while (odd.size() > 1) {
		freq[odd.back()]--; freq[odd.front()]++;
		odd.pop_back(); odd.pop_front();
	}
	s.clear();
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < freq[i] / 2; j++) 
			s.push_back('a' + i);

	string c;
	if (!odd.empty()) { 
		c = s; c.push_back(odd.back() + 'a');
		reverse(c.begin(), c.end());
	}
	else {
		c = s; reverse(c.begin(), c.end());
	}
	cout << s + c << endl;
	cin.ignore(2); return 0;
}