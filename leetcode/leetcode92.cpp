/**
 * 其實會反轉前n個的話 就會反轉指定區間
 * 假設m = 2, n = 4
 * 那從第二個node的立場，就是從他開始反轉前3個元素的鏈表
 */
class Solution {
public:
    // sucessor紀錄的是第 (n + 1) 個元素
    ListNode* successor = NULL;
    // reverse first n elements of linked list
    ListNode* reverseN(ListNode* head, int n) {
        if(n == 1) {
            successor = head->next;
            return head;
        }
        
        ListNode* last = reverseN(head->next, n - 1);
        // 反轉箭頭
        head->next->next = head;
        head->next = successor;
        // last便是新的鏈表頭
        return last;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1)
            return reverseN(head, n);
        
        // head接上反轉後的鏈表頭
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};