// 發現只要維護一個單調的遞減序列
// 最後剩下的就會是答案
// 我們要討論的是該數字可不可能當max
// 假設窗口移動，有新的拜訪者，我們拿來跟窗口最右邊的A比較
// A比拜訪者還小
// 我們一定知道，只要有這個拜訪者一起待在同一個窗口
// 那麼A一定當不成max
// 好死不死，sliding window A一定會比拜訪者先離開窗口，所以要先當max是不可能的了
// 然後繼這個拜訪者後的拜訪者比他小沒關係，畢竟第一個拜訪者會先離開窗口，第二個拜訪者還是有可能成為window的max的
// 因此deque有三種操作
// 從尾端插入：拜訪者
// 從尾端刪除：尾端的人比拜訪者小
// 從頭部刪除：窗口向後移動時
// 也由於我們需要在頭部和尾端操作，所以用deque
// 總時間：O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k > nums.size())
            return {};
        
        deque<int> dq;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(!dq.empty() && dq.front() == i - k)   // 窗口移動，頭部刪除
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])   // 窗口尾端的人比拜訪者還小
                dq.pop_back();
            dq.push_back(i);   // 新拜訪者
            if(i >= k - 1)    // 只要我們完成第一個窗口的置入，就可以開始找尋max
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};