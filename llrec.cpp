#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
using namespace std;

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

    if (head == nullptr ){
        return;
    }
    Node* temp = head->next;
    //cout << "Before" << head->val << endl;
    llpivot(temp, smaller, larger, pivot);
    //cout << "After" << head->val << endl;

    if (head->next ==nullptr){
        //cout << "Last one " << endl;
        smaller = nullptr;
        larger = nullptr;
    }

    if (head -> val > pivot){
        head->next = larger;
        larger = head;
        head = nullptr;
    }
    else {
        head->next = smaller;
        smaller = head;
        head = nullptr;
    }
}