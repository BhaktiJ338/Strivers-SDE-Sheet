/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     Node *curr=head, *tail=head;

     int len=0;

     while(curr){
          len++;
          curr = curr->next;
     } 
     k = k%len;
     if(k==0) return head;
     int cnt = len-k-1;
     curr=head;
     while(cnt--){
          curr=curr->next;
     }//reached new head
     Node *ntail = curr;
     Node *nhead = curr->next;

     while(curr->next){
          curr = curr->next;
     }//reached tail

     curr->next = head;
     ntail->next = NULL;
     return nhead;
}
