#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#include <limits>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


void printListNode(ListNode* a) {
    cout << "list nodes: ";
    while(a) {
        cout << a->val << "\t";
        a = a->next;
    }   
    cout << endl;
}