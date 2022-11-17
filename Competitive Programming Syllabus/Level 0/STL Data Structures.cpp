#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.tie(0)->sync_with_stdio(0);

	///////////////////////////////////////////////////////////////////////////

	//array: Static Array
	cout << "Array:\n";
	array<int, 10> A; A.fill(1); A[9] = 5;
	cout << "First element: " << A.front() << '\n';
	cout << "Last element: " << A.back() << '\n';
	cout << "Size: " << A.size() << "\n\n";
	
	///////////////////////////////////////////////////////////////////////////

	//vector: Dynamic Array
	cout << "Vector:\n"; //Has front, back, size 
	vector<int> V(5, 3);
	for (auto& x : V) cout << x << ' '; cout << '\n';
	V.resize(8, 2);
	for (auto& x : V) cout << x << ' '; cout << '\n';
	V.push_back(1); V.emplace_back(1);
	for (auto& x : V) cout << x << ' '; cout << '\n';
	V.pop_back();
	for (auto& x : V) cout << x << ' '; cout << '\n';
	V.assign(5, 8);
	for (auto& x : V) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	//stack: LIFO container
	cout << "Stack:\n";
	stack<int> lifo;
	cout << "Insert: ";
	for (int i = 0; i < 10; lifo.push(i++)) 
		cout << i << ' '; cout << '\n';

	cout << "Pop: ";
	for (; !lifo.empty(); lifo.pop()) cout << lifo.top() << ' ';
	cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	//queue: FIFO container
	cout << "Queue:\n";
	queue<int> fifo;
	cout << "Insert: ";
	for (int i = 0; i < 10; fifo.push(i++))
		cout << i << ' '; cout << '\n';

	cout << "Pop: ";
	for (; !fifo.empty(); fifo.pop()) cout << fifo.front() << ' ';
	cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	//deque: Double-Ended Queue
	cout << "deque:\n";
	deque<int> dq;
	cout << "push_back: "; //Also has pop_back
	for (int i = 0; i < 10; dq.push_back(i++))
		cout << i << ' '; cout << '\n';

	cout << "push_front: "; //Also has pop_front
	for (int i = 0; i < 10; dq.push_front(i++))
		cout << i << ' '; cout << '\n';

	for (auto& x : dq) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	//priority_queue: Max Heap
	cout << "priority_queue:\n";
	vector<int> heapVector = {1, 5, 2, 8, 3, 4, 6, 6, 2, 1};
	cout << "Insert Order: ";
	for (auto& x : heapVector) cout << x << ' '; cout << '\n';
	priority_queue<int> maxHeap(heapVector.begin(), heapVector.end());
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (auto& x : heapVector) minHeap.push(x);

	cout << "Max Heap: ";
	for (; !maxHeap.empty(); maxHeap.pop())
		cout << maxHeap.top() << ' '; cout << '\n';

	cout << "Min Heap: ";
	for (; !minHeap.empty(); minHeap.pop())
		cout << minHeap.top() << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	//set: Balanced Binary Search Tree with Unique Keys
	cout << "set:\n";
	vector<int> setVector = { 1, 2, 5, 8, 2, 1, 4, 6, 3, 4 };
	cout << "Insert Order: ";
	for (auto& x : setVector) cout << x << ' '; cout << '\n';
	set<int> st; //Check membership using st.count() in O(log n)
	for (auto& x : setVector) st.insert(x); //Also has erase

	cout << "Set Order: ";
	for (auto& x : st) cout << x << ' '; cout << '\n';
	cout << "Smallest Element: " << *st.begin() << '\n';
	cout << "Largest Element: " << *st.rbegin() << "\n\n";

	///////////////////////////////////////////////////////////////////////////
	
	//multiset: Balanced Binary Search Tree with Duplicate Keys
	cout << "multiset:\n";
	vector<int> multiSetVector = { 1, 2, 5, 8, 2, 1, 4, 6, 3, 4 };
	cout << "Insert Order: ";
	for (auto& x : multiSetVector) cout << x << ' '; cout << '\n';

	//Here mst.count() counts the occurences in O(cnt)
	multiset<int> mst; //Check membership using mst.find() in O(log n)

	//Careful, mst.erase(key) removes all occurences
	//Instead use mst.erase(mst.find(key))
	for (auto& x : multiSetVector) mst.insert(x);

	cout << "Multiset Order: ";
	for (auto& x : mst) cout << x << ' '; cout << "\n\n";
	auto [first, last] = mst.equal_range(2); //Range [first, last) has value 2

	///////////////////////////////////////////////////////////////////////////

	//map: Balanced Associative Binary Search Tree with Unique Keys
	cout << "map:\n";
	vector<int> mapVector = { 1, 2, 5, 8, 2, 1, 4, 6, 3, 4 };
	cout << "Insert Order: ";
	for (auto& x : mapVector) cout << x << ' '; cout << '\n';
	map<int, int> mp; //Check membership using mp.count() in O(log n)
	for (auto& x : mapVector) mp[x] = rand() % 10; //Also has erase

	cout << "Map Pairs:\n"; for (auto& [key, val] : mp)
		cout << key << ' ' << val << '\n'; cout << '\n';	

	///////////////////////////////////////////////////////////////////////////

	//string: vector of characters
	cout << "string:\n";
	string str1(3, 'a'); string str;
	for (int i = 0; i < 10; i++) {
		char c = i & 1 ? 'A' : 'a';
		//Also has pop_back
		str.push_back(c + (rng() % 6));
	}
	str += str1; cout << str << '\n';
	cout << "Sequence 'aaa' first found at index " << str.find("aaa") << '\n';
	cout << "First vowel found at " << str.find_first_of("aeiouAEIOU") << '\n';
	cout << "Last vowel found at " << str.find_last_of("aeiouAEIOU") << '\n';
	cout << "Substring starting at index 2 of length 5: " << str.substr(2, 5) << '\n';

	///////////////////////////////////////////////////////////////////////////

	//Check the other STL Containers here: https://cplusplus.com/reference/stl/
	//list, forward_list, multimap, unordered_set
	//unordered_map, unordered_multiset, unordered_multimap
}