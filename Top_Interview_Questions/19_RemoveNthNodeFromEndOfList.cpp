class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;//等待右指针走n步再走
        ListNode* right = head;
        ListNode* prev = head;//删除节点前驱
        while(n-- > 0)
            right = right->next;
        //一起走，右指针到时，做指针即为要找的
        while(right) {
            right = right->next;
            prev = left;
            left = left->next;
        }
        //delete 首元素特殊处理
        if(prev != left) {
            prev->next = left->next;
            delete left; 
            left = nullptr;
        } else {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
        return head;
    }
};