// if call i times of book, time complexity: O(i^2)
// beats over 69% of submission
static auto _ = [](){ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class MyCalendarThree {
    map<int, int> seg;
public:
    MyCalendarThree() { }
    
    int book(int start, int end) {
        seg[start]++;
        seg[end]--;
        int k = 0, act = 0;
        for(pair<int, int> p : seg)
            k = max(k, act += p.second);
        return k;
    }
};

// *segment tree
// use reset() because we use smart pointer
// beats over 94% of submission
class MyCalendarThree {
private:
    struct Node {
        int s, m, e, k;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        // m = -1 just means a initial state
        Node(int start, int end, int count):s(start), m(-1), e(end), k(count){}
    };
    int max_;
    unique_ptr<Node> _root;
    // each time we will start traverse from the root node
    void add(Node* root, int start, int end) {
        if(root->m != -1){
            // this if-condition is used to find the right root node to start
            // -1 means curr existing leaf nodes
            if(end <= root->m)
                // if belong to left segment
                add(root->left.get(), start, end);
            else if(start >= root->m)
                // if belong to right segment
                add(root->right.get(), start, end);
            else {
                // if cross both sides of segment
                add(root->left.get(), start, root->m);
                add(root->right.get(), root->m, end);
            }
            return;
        }

        // <start, end> must be in the scope of the current node
        // so we don't need to check whether it will be out of range
        if(start == root->s && end == root->e)
            // if the schedule is same
            // we don't need to add node
            // just add count
            max_ = max(max_, ++root->k);
        else if(start == root->s) {
            // split if left segment
            root->m = end;
            root->left.reset(new Node(start, root->m, root->k + 1));
            root->right.reset(new Node(root->m, root->e, root->k));
            max_ = max(max_, root->k + 1);
        } else if(end == root->e) {
            // split if right segment
            root->m = start;
            root->left.reset(new Node(root->s, root->m, root->k));
            root->right.reset(new Node(root->m, root->e, root->k + 1));
            max_ = max(max_, root->k + 1);
        } else {
            // split if mid segment
            root->m = start;
            root->left.reset(new Node(root->s, root->m, root->k));
            root->right.reset(new Node(root->m, root->e, root->k));
            add(root->right.get(), start, end);
        }
    }
public:
    MyCalendarThree():max_(0) {
        _root.reset(new Node(0, 1000000000, 0));
    }
    
    int book(int start, int end) {
        add(_root.get(), start, end);
        return max_;
    }
};