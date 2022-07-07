/**
 * linked list真的不能倒著遍歷嗎？
 */
class Solution {
public:
    ListNode* left;
    // 由於stack的特性
    // res第一次終止(也就是right == NULL)之後
    // 會倒著遍歷linked list
    bool traverse(ListNode* right) {
        if(right == NULL)
            return true;
        
        bool res = traverse(right->next);
        res = res && (left->val == right->val);
        left = left->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        left = head;
        return traverse(head);
    }
};
/**
 * 快慢指針：快指針一次移動兩步，慢指針一次移動ㄧ步
 * 從慢指針開始反轉鏈表
 * 但是有分兩種情況
 * 若鏈表有奇數個node，快指針會指向最後一個，慢指針會指向中間往右一位 (把中心留在左邊)
 * 若有偶數個node，快指針會指向NULL，慢指針會指向n/2 + 1
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        // pre -> cur -> nxt
        // NULL -> head -> head.next
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 鏈表有奇數個node，中心要留在左邊，所以慢指針再往右一位
        if(fast != NULL)
            slow = slow->next;
        
        // 左指針是左邊的鏈表頭
        ListNode* left = head;
        // 右指針是右邊的鏈表頭
        ListNode* right = reverse(slow);
        
        while(right != NULL) {
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};