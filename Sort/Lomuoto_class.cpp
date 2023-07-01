#include "Lomuoto_class.h"
#include <iostream>

Node* List::Add(int _val, Node* node = NULL){
    Node* elem = new Node;
    elem->val = _val;
    size++;
    if (node == NULL){
        if (head == NULL){
            elem->next = NULL;
            head = elem;
        }
        else{
            elem->next = head;
            head= elem;
        }
        return elem;
    }
    elem->next = node->next;
    node->next = elem;
    return elem;
}

void List::Print(){
    if (head == NULL) {std::cout << "Список пуст!" << std::endl; return;}
    Node* p = head;
    do {
        std::cout << p->val << " ";
        p->next = p->next;
    } while(p != NULL);
    std::cout << std::endl;
}