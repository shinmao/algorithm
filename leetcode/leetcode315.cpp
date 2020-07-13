// beats over 59% of submission
class Solution {
private:
    vector<int> count;
    struct Node {
        int id;
        int val;
        int s;
        int ls;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        Node(int id_, int val_, int s_): id(id_), val(val_), s(s_), ls(0), left(nullptr), right(nullptr) {}
    };
    unique_ptr<Node> _root;
    
    void add(Node* root, int id, int val) {
        if(val > root->val and root->right != nullptr) {
            add(root->right.get(), id, val);
            count[id] += root->ls;
            return;
        }
        if(val <= root->val and root->left != nullptr) {
            ++root->ls;
            add(root->left.get(), id, val);
            return;
        }
            
        if(val > root->val) {
            root->right.reset(new Node(id, val, root->s + 1));
            count[id] = root->s + 1 + root->ls;
        } else if(val <= root->val) {
            root->left.reset(new Node(id, val, root->s));
            count[id] = root->s + root->ls;
            ++root->ls;
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty()) return {};
        [](){ios::sync_with_stdio(false);cin.tie(0);return 0;}();
        count.assign(nums.size(), 0);
        // add root node
        _root = make_unique<Node>(nums.size() - 1, nums[nums.size() - 1], 0);
        for(int i = nums.size()-2; i > -1; --i) {
            add(_root.get(), i, nums[i]);
        }
        return count;
    }
};