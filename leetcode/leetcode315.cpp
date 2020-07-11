// beats over 36% of submission
class Solution {
private:
    vector<int> input;
    vector<int> count;
    struct Node {
        int id;
        int val;
        int s;
        int ls;    // whole num smaller than cur node
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
        reverse(nums.begin(), nums.end());
        input.assign(nums.begin(), nums.end());
        count.assign(input.size(), 0);
        // add root node
        _root = make_unique<Node>(0, input[0], 0);
        for(int i = 1; i < input.size(); ++i) {
            add(_root.get(), i, input[i]);
        }
        reverse(count.begin(), count.end());
        return count;
    }
};