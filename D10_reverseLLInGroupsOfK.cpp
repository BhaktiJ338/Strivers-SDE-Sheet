#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *reverse(Node *head, int n, int b[], int i){
	if(!head || !head->next || n<1) return head;

	Node *curr = head, *nxt=NULL, *prev=NULL;
	while(i<n && b[i]==0) i++;
	int cnt = b[i];
	while(curr && cnt-- && i<n){ //reverse current group
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}

	if(curr && i>=n){ //array finished
		return head;
	}
	if(curr){ //reverse next group
		head->next = reverse(nxt, n, b, i+1);
	}
	return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return reverse(head, n, b, 0);
}
