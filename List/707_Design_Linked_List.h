//
// Created by 张永斌 on 2021/3/10.
//

#ifndef LEETCODE_707_DESIGN_LINKED_LIST_H
#define LEETCODE_707_DESIGN_LINKED_LIST_H

#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    /** Initialize your data structure here. */
    MyLinkedList(){
        newList = new LinkedNode(0);
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index > size - 1 || index < 0) {
            return -1;
        }
        LinkedNode * p = newList->next;
        while (index > 0) {
            p = p->next;
            -- index;
        }
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* temp = new LinkedNode(val);
        temp->next = newList->next;
        newList->next = temp;
        ++ size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode *temp = new LinkedNode(val);
        LinkedNode * p = newList;
        int index = size - 1;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = temp;
        ++ size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;

        LinkedNode *temp = new LinkedNode(val);
        LinkedNode * p = newList;

        while (index-- ) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
        ++size;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index > size - 1 || index < 0)
            return;

        LinkedNode * p = newList;

        while (index--) {
            p = p->next;
        }

        LinkedNode * temp = p->next;
        p->next = temp ->next;
        delete temp;
        --size;

    }

    void Print() {
        if(newList == nullptr) return;
        LinkedNode* p = newList;
        while(p != nullptr) {
            cout << p->val << " " ;
            p = p->next;
        }
        cout << endl;
    }
private:
    LinkedNode *newList;
    int size;
};



void Test() {
    MyLinkedList * linkedList = new MyLinkedList();

    linkedList->addAtHead(1);
    linkedList->Print();
    cout << linkedList->get(1) << endl;
    linkedList->addAtTail(3);
    linkedList->Print();
    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList->Print();
    linkedList->get(1);            //返回2
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    linkedList->Print();
//    linkedList->get(1);            //返回3


}

#endif //LEETCODE_707_DESIGN_LINKED_LIST_H


