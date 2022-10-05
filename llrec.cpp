#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llppivot (Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head->next == nullptr){
		if(head->val <= pivot){
			smaller = head;
			return;
		}
		if(head->val > pivot){
			larger = head;
			return;
		}
	}
	else if(head->val <= pivot){
		smaller = head;
		llpivot(head->next, smaller->next, larger, pivot);
	}
	else if(head->val > pivot){
		larger = head;
		llpivot(head->next, smaller, larger->next, pivot);
	}
	head = NULL;
	head->next = nullptr;
}


