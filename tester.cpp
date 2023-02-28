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

    Node* less;
    Node* more;

    Node* tick = a;
    while (tick != nullptr){
        cout << tick->val << " at: " << tick << endl;
        tick = tick->next;
    }
    cout << "less at: " << less << endl;
    cout << "more at: " << more << endl;

    llpivot(a, less, more, 5);




    /*
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




    Node* smaller = nullptr;
    Node* larger = nullptr;

    llpivot(a, smaller, larger, 5);


    Node * temp = smaller;
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


    cout << endl << "TESTS SATURDAY" << endl;

    Node* empty = nullptr;
    Node* x;
    Node* y;

    cout << "X = " << x << endl;
    cout << "y = " << y << endl;

    llpivot(empty, x, y, 5);

    cout << "Head: " << empty << endl;
    cout << "x = " << x << endl;
    cout << "y " << y << endl;
    */
    return 0;
}