//Given the head of a linked list, remove the nth node from the end of the list and return its head.
//Input: head = [1, 2, 3, 4, 5], n = 2
//Output : [1, 2, 3, 5]

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//直接在我脑海中出现的思路是建了vector，把每个节点的值都存进去，然后通过获取v.size() - n,一直访问到该节点并执行删除操作
//这样的方式应该一定可行，但是perfermance肯定有很大的提升空间
//学习代码随想录中的思路，可以通过快慢指针的思路，先让快指针向前进n+1个节点
//然后在一个while loop中使快慢指针同时前进直到，快指针的next为空则循环停止
//需要注意的是，在进行删除操作的时候我们需要确保执行删除操作的指针指向被删除节点的前一个
//所以我们让快指针先前进n+1而不是n个节点，这样慢指针最后指向倒数n+1个节点

//dummuyhead的一大好处是不需要对原先的头节点进行专门的boundary case判断操作

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* fast{ dummyhead };
        ListNode* slow{ dummyhead };
        int count = 0;
        while (fast && n + 1 > count) {// count + because dummy_head is added
            fast = fast->next;
            count++;
        }
        //fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyhead->next;
    }
};
