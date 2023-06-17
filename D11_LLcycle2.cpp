Node *firstNode(Node *head)
{
    if(!head) return false;
	Node *slow=head, *fast=head;
    
    while(fast && fast->next && slow && slow->next){
        fast = fast->next->next;
        slow = slow->next;

        if(slow==fast) {
            fast = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
