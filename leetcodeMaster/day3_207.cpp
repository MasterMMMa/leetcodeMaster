//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

#include <iostream>
#include <vector>
using namespace std;
  //Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        if (!head) return head;
        ListNode* n = head;
        while (n->next) {
            if (n->next->val == val) {
                n->next = n->next->next;
            }
            else {
                n = n->next;
            }
        }
        delete n;
        return head;
    }
};

  //int main() {
  //    Solution s;
  //    //test case 1
  //    ListNode* head = new ListNode(1);
  //    head->next = new ListNode(2);
  //    head->next->next = new ListNode(6);
  //    head->next->next->next = new ListNode(3);
  //    head->next->next->next->next = new ListNode(4);
  //    head->next->next->next->next->next = new ListNode(5);
  //    head->next->next->next->next->next->next = new ListNode(6);
  //    int val = 6;
  //    ListNode* sol = s.removeElements(head, val);
  //    // output the linked list
  //    //cout << "111";
  //    while (sol) {
		//  cout << sol->val << " ";
		//  sol = sol->next;
	 // }

  //}