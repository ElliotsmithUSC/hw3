#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == nullptr){
		//std::cout << "empty input list" << std::endl;
		smaller = nullptr;
		larger = nullptr;
		return;
	}

	Node* headnext = head->next;

	if(head->next == nullptr){
		if(head->val <= pivot){
			smaller = head;
			smaller->next = nullptr;
			larger = smaller->next;
		}
		else if(head->val > pivot){
			larger = head;
			larger->next = nullptr;
			smaller = larger->next;
		}
	}
 	else if(head->val <= pivot){
		smaller = head;
		llpivot(headnext, smaller->next, larger, pivot);
	}
	else if(head->val > pivot){
		larger = head;
		llpivot(headnext, smaller, larger->next, pivot);
	}
	head = nullptr;
}


