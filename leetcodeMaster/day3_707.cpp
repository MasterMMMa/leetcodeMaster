//Design your implementation of the linked list.You can choose to use a singly or doubly linked list.
//A node in a singly linked list should have two attributes : val and next.val is the value of the current node, and next is a pointer / reference to the next node.
//If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list.Assume all nodes in the linked list are 0 - indexed.
//
//Implement the MyLinkedList class :
//
//	MyLinkedList() Initializes the MyLinkedList object.
//	int get(int index) Get the value of the indexth node in the linked list.If the index is invalid, return -1.
//	void addAtHead(int val) Add a node of value val before the first element of the linked list.After the insertion, the new node will be the first node of the linked list.
//	void addAtTail(int val) Append a node of value val as the last element of the linked list.
//	void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list.If index equals the length of the linked list, the node will be appended to the end of the linked list.If index is greater than the length, the node will not be inserted.
//	void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

//反思：代码操纵能力还是不够扎实，其实是非常基本的取construct一个linked list,在具体实现的各种小细节中存在需要疏忽。
//另一方面也觉得linked list 不难解决，写的过程也有点不耐烦，多思考，认真的解决每一个问题！
class LinkedNode {
public:
    LinkedNode* next;
    int val;
    LinkedNode (int val , LinkedNode* next) : val(val), next(next) {}
    LinkedNode (int val) : val (val) , next(nullptr){}
};

class MyLinkedList {
private:
    LinkedNode* head;

public:
    //constructor
    MyLinkedList(int size, LinkedNode* head) : head(head) {}
    MyLinkedList() : head(nullptr) {}

    int get(int index) {
        if (index < 0 || !head) return -1;//invalid index
        if (index == 0 && head) return head->val;
        LinkedNode* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
            if (!temp) return -1;
        }
        return temp->val;

    }

    void addAtHead(int val) {
        LinkedNode* newhead = new LinkedNode(val);
        if (!head) {
            head = newhead;
        }
        else {
            newhead->next = head;
            head = newhead;
        }
    }

    void addAtTail(int val) {
        LinkedNode* tail = new LinkedNode(val);

        if (!head) {
            head = tail;
            return;
        }
        LinkedNode* ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }

        ptr->next = tail;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        int count = 0;
        LinkedNode* temp = head;
        while (count < index - 1 && temp)//loop need to be stoped at index -1 then perform insertion
        {
            temp = temp->next;
            count++;
        }
        if (!temp) return;
        else {
            LinkedNode* ptr = temp->next;
            temp->next = new LinkedNode(val, ptr);
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || !head) return;
        if (index == 0) {
            LinkedNode* temp = head;
            head = head->next;
            return;
        }
        int count = 0;
        LinkedNode* ptr = head;
        while (count < index - 1 && ptr) {
            ptr = ptr->next;
            count++;
        }
        if (!ptr || !ptr->next) return;
        else {
            LinkedNode* temp = ptr->next->next;
            ptr->next = temp;
        }
    }


};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */