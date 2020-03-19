# Middle of linked list

Find the middle node of linked list. However, you can only iterate throught the linked list for one time.

## lintcode228
* [Two pointers](https://github.com/shinmao/algorithm/blob/master/mid-of-linked-list/lintcode228-1.java): Here I use two pointers, one is slower which would take one step for each time, another one is faster which would take two steps for each time. The interesting trick to get the middle node here is making slower pointer and faster pointer step out until faster pointer arrive at the tail of linked list, which is `null`, then the slower pointer would be on middle node. One thing need to be care about is the impact of list length on the breaking condition of while loop: breaking condition would be either `fast == null` or `fast.next == null` based on the case.