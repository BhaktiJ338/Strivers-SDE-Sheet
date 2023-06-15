Node* findIntersection(Node *l1, Node *l2)
{
    if(!l1 || !l2) return NULL;
    Node *t1=l1, *t2=l2;

    while(t1 != t2){
        if(!t1) t1 = l2;
        else t1 = t1->next;
        
        if(!t2) t2 = l1;
        else t2 = t2->next;
    }
    return t1;
}
