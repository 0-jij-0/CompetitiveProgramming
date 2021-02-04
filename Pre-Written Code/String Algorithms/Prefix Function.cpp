#include <string>
#include <iostream>
#include <vector>
using namespace std;

//For each i in the returned vector, the number represents the length of 
//the longest proper prefix equal to the suffix ending at index i, both in the substring s[0..i]
//Proper prefix means prefix != string
vector<int> prefixFunction(string& s) {
	vector<int> pf(s.size(), 0);
	for (int i = 1; i < s.size(); i++) {
		int j = pf[i - 1];
		while (j > 0 && s[j] != s[i]) { j = pf[j - 1]; }
		if (s[j] == s[i]) { j++; }
		pf[i] = j;
	}
	return move(pf);
}

//checks if s is in t
//t and s can NOT contain the character #
bool stringMatch(string& t, string& s) {
	string temp = s + '#' + t;
	auto pf = prefixFunction(temp);

	for (int i = 0; i < pf.size(); i++) {
		if (pf[i] == s.size()) { return true; }
	}

	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}