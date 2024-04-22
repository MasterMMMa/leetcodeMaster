//Given a linked list, swap every two adjacent nodes and return its head.You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

//Input: head = [1, 2, 3, 4]
//Output : [2, 1, 4, 3]

#include <vector>
#include <iostream>
using namespace std;
//??????dummy head???????????????????????????????????????
//???linked list ? pointer?????????????????????????
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

//initlize a dummy head to better keep track of the lsit
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(999);
        dummyhead->next = head;
        ListNode* curr = dummyhead;
        while (curr->next && curr->next->next) {//next two node exsits
            ListNode* temp1 = curr->next;
            ListNode* temp2 = curr->next->next->next;
            temp1->next->next = temp1;
            curr->next = temp1->next;
            temp1->next = temp2;
            curr = curr->next->next;
        }
        return dummyhead->next;
    }
};