//Given the head of a singly linked list, reverse the list, and return the reversed list.
//Input: head = [1, 2, 3, 4, 5]
//Output : [5, 4, 3, 2, 1]
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr){}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x),next(next) {}
};

//我初次解题的思路是把每个元素的值存到一个vector里面，然后再从vector里面取出来，构建一个新的linked list
//更巧妙的解法是直接在原来的linked list上面进行操作，不需要额外的空间，

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return head;//empmty list
		if (head && !head->next) return head; // only one element
		vector<int> v;
		ListNode* ptr = head;
		while (ptr) {
			v.push_back(ptr->val);
			ptr = ptr->next;
		}
		//print the vector
		//cout << "db2:    ";
		//for (int i = 0; i < v.size(); i++) {
		//	cout << v[i]->val << " ";
		//}
		cout << endl;
		int size = v.size() - 1;
		ListNode* newHead = new ListNode(v[size]);
		ListNode* cur = newHead;
		for (int i = size - 1 ; i >= 0; i--) {
			cur->next = new ListNode(v[i]);
			cur = cur->next;
		}
		return newHead;
	}
};

class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr) {
			ListNode* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		return prev;//需要返回prev，因为curr在最后一个元素的时候是nullptr
	}
};

int main() {
		ListNode* head = new ListNode(1);
	ListNode* second = new ListNode(2);
	ListNode* third = new ListNode(3);
	ListNode* fourth = new ListNode(4);
	ListNode* fifth = new ListNode(5);
	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	Solution s;
	ListNode* newHead = s.reverseList(head);
	//print the new list
	cout <<"priint the new list:    ";
	while (newHead) {
		cout << newHead->val << " ";
		newHead = newHead->next;
	}

	return 0;
}