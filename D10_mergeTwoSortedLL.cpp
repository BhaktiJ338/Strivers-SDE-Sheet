#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *l1, Node<int> *l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    if(l1->data > l2->data) swap(l1, l2);
    Node<int> *nhead=l1;

    while(l1 && l2){
        Node<int> *temp = NULL;
        while(l1 && l1->data<=l2->data){
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    
    return nhead;
}
