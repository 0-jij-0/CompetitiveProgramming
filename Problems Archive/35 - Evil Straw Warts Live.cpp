#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(string &s, int i, int j) {
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

bool impossible(string s) {
	vector<int> letter_count;
	letter_count.resize(26, 0);
	for (int i = 0; i < s.size(); i++) {
		int idx = s[i] - 'a';
		letter_count[idx]++;
	}

	if (s.size() % 2 == 0) {
		for (int i = 0; i < 26; i++) {
			if (letter_count[i] % 2 == 1) { return true; }
		}
		return false;
	}
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (letter_count[i] % 2 == 1) { count++; }
	}
	if (count != 1) { return true; }
	return false;
}

int bubble_sort(vector<pair<int, char>> &letters) {
	int count = 0; bool finished = false;
	for (int i = 0; i < letters.size(); i++) {
		finished = true;
		for (int j = 0; j < letters.size() - 1; j++) {
			if (letters[j].first > letters[j + 1].first) {
				finished = false;
				pair<int, char> temp = letters[j];
				letters[j] = letters[j + 1];
				letters[j + 1] = temp;
				count++;
			}
		}
		if (finished) { return count; }
	}
	return count;
}

int prepare(string &str) {
	vector<pair<int, char>> letters;

	vector<int> letter_count;
	letter_count.resize(26, 0);
	for (int i = 0; i < str.size(); i++) {
		int idx = str[i] - 'a';
		letter_count[idx]++;
	}

	vector<int> letter_used;
	letter_used.resize(26, 0);

	for (int i = 0; i < str.size(); i++) {
		int idx = str[i] - 'a';
		if (letter_count[idx] % 2 == 1) {
			if (letter_used[idx] < letter_count[idx] / 2) {
				pair<int, char> p(1, str[i]);
				letters.push_back(p);
				letter_used[idx]++;
				continue;
			}
			if (letter_used[idx] > letter_count[idx] / 2) {
				pair<int, char> p(3, str[i]);
				letters.push_back(p);
				letter_used[idx]++;
				continue;
			}
			pair<int, char> p(2, str[i]);
			letters.push_back(p);
			letter_used[idx]++;
			continue;
		}
		if (letter_used[idx] < letter_count[idx] / 2) {
			pair<int, char> p(1, str[i]);
			letters.push_back(p);
			letter_used[idx]++;
			continue;
		}
		
		pair<int, char> p(3, str[i]);
		letters.push_back(p);
		letter_used[idx]++;
		continue;		
	}

	int count = bubble_sort(letters);

	for (int i = 0; i < str.size(); i++) {
		str[i] = letters[i].second;
	}

	return count;
}

int search(string &str, char c, int i) {
	if (str[i] == c) { return i; }
	return search(str, c, i - 1);
}

int bubbleFromTo(string &str, int from, int to) {
	int count = 0;
	while (from != to) {
		swap(str, from, from + 1);
		from++; count++;
	}
	return count;
}

int min_swaps(string &str) {
	if (impossible(str)) { return -1; }
	int count = prepare(str);

	if (str.size() % 2 == 1) {
		int mid = str.size() / 2;
		for (int i = 0; i < str.size() / 2; i++) {
			
			int idx = search(str, str[i], str.size() - 1 - i);
			count += bubbleFromTo(str, idx, str.size() - 1 - i);
		}
	}

	else {
		int mid = str.size() / 2;
		for (int i = 0; i < str.size() / 2; i++) {

			int idx = search(str, str[i], str.size() - 1 - i);
			count += bubbleFromTo(str, idx, str.size() - 1 - i);
		}
	}

	return count;
}

int main() {
	int n; cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int res = min_swaps(s);
		if (res == -1) { cout << "Impossible" << endl; }
		else { cout << res << endl; }
	}
	
	cout << endl; cin.ignore(2); return 0;
}
