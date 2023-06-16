#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* middleNode(LinkedListNode<int> *head){
    LinkedListNode<int> *slow=head, *fast=head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

LinkedListNode<int> *reverse(LinkedListNode<int> *head){
     LinkedListNode<int> *curr=head, *nxt, *prev=NULL;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *mid = middleNode(head);
    mid = reverse(mid);

    while(curr && mid){
        if(curr->data != mid->data) return false;
        curr = curr->next;
        mid = mid->next;
    }
    return true;
}
