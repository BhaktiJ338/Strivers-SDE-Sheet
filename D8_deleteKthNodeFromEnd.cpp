/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    Node *t1, *t2, cnt=k;
    t1=head;t2=head;
    for(int i=0; i<k; i++){
        t1= t1->next;
        t2= t2->next;
    }
    if(!t1) return head->next;
    
    t2 = head;
    
    while(t1->next){
        t1= t1->next;
        t2= t2->next;
    }
    t2->next = t2->next->next;
    return head;
}
