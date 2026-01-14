// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = tail = nullptr;
    for (Node *curr = source.head; curr; curr = curr->next) {
        //cout << "balls\n";
        push_back(curr->info);
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    Node* next;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }

}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    for (Node *curr = head; curr; curr = curr->next) {
        sum += curr->info;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
	for (Node *left = head; left; left = left->next) {
		if (left->info == value) return true;
	}
	return false;
}

// returns maximum value in list, or 0 if empty lit
int IntList::max() const {
    if (!head) return 0;
    int max = head->info;
    for (Node *curr = head; curr; curr = curr->next) {
        if (max < curr->info) max = curr->info;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!head) return 0.0;
    return float(this->sum()) / this->count();
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
	head = new Node{value, head};
    if (!tail) tail = head;
}

// append value at end of list
void IntList::push_back(int value) {
    //std::cout << "balls\n";
    if (!head) {
        tail = head = new Node{value, nullptr};
    } else {
        tail->next = new Node{value, nullptr};
        tail = tail->next;
    }
 
}

// return count of values
int IntList::count() const {
    int count = 0;
    for (Node *curr = head; curr; curr = curr->next) {
        count++;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //Node* curr = head;
    Node* next;
    while (head) {
        next = head->next;
        delete head;
        head = next;
    }
    head = tail = nullptr;
    for (Node *curr = source.head; curr; curr = curr->next) {
        //cout << "balls\n";
        push_back(curr->info);
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

