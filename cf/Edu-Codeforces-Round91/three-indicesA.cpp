// TLE
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
 
vector<int> res;
 
struct Node {
	int val;
	int id;
	set<int, greater<int>> l;  // stored id on the lf side
	unique_ptr<Node> left;
	unique_ptr<Node> right;
	Node(int id, int val):id(id), val(val), left(nullptr), right(nullptr) {}
};
 
void add(Node* root, int id, int val) {
	if(val > root->val and root->right != nullptr) {
		add(root->right.get(), id, val);
		return;
	}
	if(val <= root->val and root->left != nullptr) {
		root->l.insert(id);
		add(root->left.get(), id, val);
		return;
	}
 
	if(val > root->val){
		root->right.reset(new Node(id, val));
	} else {
		root->l.insert(id);
		root->left.reset(new Node(id, val));
	}
}
 
void check(Node* root) {
	if(root->right != nullptr) {
		Node* r = root->right.get();
		if(root->l.size() != 0) {
			if(*root->l.begin() > r->id) {
				res.emplace_back(root->id + 1);
				res.emplace_back(r->id + 1);
				res.emplace_back(*root->l.begin() + 1);
				return;
			}
		}
		if(r->left != nullptr) {
			Node* rl = r->left.get();
			res.emplace_back(root->id + 1);
			res.emplace_back(r->id + 1);
			res.emplace_back(rl->id + 1);
			return;
		}
		check(r);
	}
	if(root->left != nullptr) {
		check(root->left.get());
	}
}
 
int main() { _
	int tc;
	cin >> tc;
	while(tc--) {
	    res.clear();
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; ++i)
			cin >> arr.at(i);
 
		unique_ptr<Node> _root = make_unique<Node>(0, arr[0]);
		for(int i = 1; i < n; ++i)
			add(_root.get(), i, arr[i]);
		
		check(_root.get());
		if(res.size() == 0) cout << "NO" << '\n';
		if(res.size() == 3) {
			cout << "YES" << '\n';
			for(int i = 0; i < 3; ++i) {
				if(i > 0) cout << " ";
				cout << res[i]; 
			}
			cout << '\n';
		}
	}
 
    return 0;
}