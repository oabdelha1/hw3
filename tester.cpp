//
// Created by Omar Abd-Elhamid on 2/17/23.
//
#include "llrec.h"
#include <iostream>

using namespace std;

struct Odd{
    bool operator()(int x){
        return (x % 2) == 1;
    }
};

int main(){

    Node* f = new Node(8, nullptr);
    Node* e = new Node(7, f);
    Node* d = new Node(6, e);

    Node* c = new Node(3, d);
    Node* b = new Node(2, c);
    Node* a = new Node(1, b);

    Node* temp1 = a;
    while (temp1 != nullptr){
        cout << temp1->val << endl;
        temp1 = temp1->next;
    }

    Odd filter;

    Node* temp2 = llfilter(a, filter);

    while (temp2!=nullptr){
        cout << temp2->val << endl;
        temp2 = temp2->next;
    }



    /*
    Node* smaller = nullptr;
    Node* larger = nullptr;

    llpivot(a, smaller, larger, 5);


    temp = smaller;
    cout << "Smaller" << endl;
    while (temp!= nullptr){
        cout << temp->val << endl;
        temp = temp->next;
    }

    temp = larger;
    cout << "Larger: " << endl;
    while (temp != nullptr){
        cout << temp->val << endl;
        temp = temp->next;
    }
     */

    return 0;
}