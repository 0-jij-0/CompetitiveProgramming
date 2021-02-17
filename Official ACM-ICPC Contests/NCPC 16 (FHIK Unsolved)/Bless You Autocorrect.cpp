#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
vector<string> dictionary;
 
struct node {
	int autoComplete;
	node* child[26];
 
	node() { autoComplete = NULL; for (int i = 0; i < 26; i++) { child[i] = NULL; } }
	node(int ans) : autoComplete(ans) {
		for (int i = 0; i < 26; i++) { child[i] = NULL; }
	}
};
 
void addStr(node* root, string& s) {
	node* cur = root;
 
	for (int i = 0; i < s.size(); i++) {
		if (cur->child[s[i] - 'a'] != NULL) { 
			cur = cur->child[s[i] - 'a']; 
		}
		else {
			node* newN = new node(dictionary.size());
			cur->child[s[i] - 'a'] = newN;
			cur = newN;
		}
	}
 
	dictionary.push_back(s);
}
 
int neededKey(node* root, string& s, int i) {
	if (i >= s.size()) { return 0; }
	if (root == NULL) { return s.size() - i; }
	int ans = 0;
	node* cur = root;
	string word = dictionary[cur->autoComplete];
 
	int originalI = i;
	while (i < min(word.size(), s.size()) && word[i] == s[i]) { 
		i++;
		if (i < s.size()) cur = cur->child[s[i] - 'a'];
	}
 
	if (originalI == i) {
		cur = cur->child[s[i] - 'a'];
		return 1 + neededKey(cur, s, i + 1);
	}
	else {
		int backSpace = word.size() - i + 2;
		int moved = i - originalI;
 
		ans += min(backSpace, moved);
		ans += neededKey(cur, s, i);
		return ans;
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n, m; cin >> n >> m;
 
	node* root = new node();
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		addStr(root, s);
	}
 
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		cout << neededKey(root->child[s[0]-'a'], s, 0) << endl;
	}
}