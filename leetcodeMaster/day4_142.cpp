//Given the head of a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
//
//Do not modify the linked list.

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//use two poninter techniques,fast ptr 2step each time, slow ptr 1 step each
//假设存在环的情况
//if cycle exsits, slow pointer will move forward for X and Y can make make us get following equations
//2(D + X) = D+X+n(X+Y) , n means fast already go through n cycles before meet
//then we get D = (n - 1) (X+Y) + Y, assume slow pointer start again from head, we get get the conclusion that they will meet again at the start of the cycle.
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* ptr1 = head;
                ListNode* ptr2 = fast;
                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1;
            }
        }
        return nullptr;
    }
};