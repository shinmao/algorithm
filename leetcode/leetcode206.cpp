/**
 * 看看recursion的步驟
 * 第一步是明確function的定義：輸入一個head，他會將以一個以head為起點的linked list反轉，並return之後的起點
 * 再來看看reverse linked list的演算法
 * 原本是長這樣的：1->2->3->4->5->6
 * 1->2<-3<-4<-5<-6
 * 1-><-2<-3<-4<-5<-6
 * 1<-2<-3<-4<-5<-6
 * 算法流程大概是這樣，linked list被反轉過來囉
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        
        ListNode* last = reverseList(head->next);
        // 這裡的->next->next就是反轉箭頭的步驟
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};
/**
 * 更簡單的寫法
 * 這個寫法可以用在反轉整個鏈表
 * pre指向前一個
 * cur指向當前的，把cur指向pre就反轉了
 * nxt指向下一個要拜訪的，也就是cur之後的位置
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        
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
};