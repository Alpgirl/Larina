#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

struct Node {
    int key;
    Node* next = NULL;
}; 

struct Queue{
    Node* head = NULL;
    Node* last = NULL;
    int size = 0;
};

void push(Queue &L, int value, std::ofstream &out){
    if (L.size == 0){
        L.head = new Node;
        L.head->next = NULL;
        L.head->key = value;
        L.last = L.head;
    }
    else{
        L.last->next = new Node;
        L.last = L.last->next;
        L.last->key = value;
        L.last->next = NULL;
    }
    L.size++;
    out << "ok" << std::endl;
}

void pop(Queue &L, std::ofstream &out, std::string ch){
    Node* del_elem = L.head;
    if (L.head != 0){
        if (ch == "yes") out << del_elem->key << std::endl;
        L.head = L.head->next;
        L.size--;
        delete del_elem;
    }
    else out << std::endl;
}

void front(Queue &L, std::ofstream &out){
    if (L.size != 0)
        out << L.head->key << std::endl;
    else out << std::endl;
}

void size(Queue &L, std::ofstream &out){
    out << L.size << std::endl;
}

void clear(Queue &L, std::ofstream &out){
    if (L.size != 0){
        while(L.size != 0)
            pop(L, out, "no");
        out << "ok" << std::endl;
    }
    else out << std::endl;
}

void exit(std::ofstream &out){
    out << "bye" << std::endl;
    abort();
}

void printQueue(Queue &L){
    if(L.size != 0){
        Node* current = new Node;
        current = L.head;
        while (current != NULL){
            std::cout<< current->key << std::endl;
            current = current->next;
        }
    }
}
int main(){
    int N, el;
    Queue L;
    std::string s, com;
    std::ifstream on;
    std::ofstream out;

    on.open("input.txt");
    out.open("output.txt");

    if (!on or !out){
        std::cout << "Can't open the file" << std::endl;
        return -1;
    }

    std::map <std::string, int> action;
    action["push"]  = 1; 
    action["pop"]   = 2;
    action["front"]  = 3;
    action["size"]  = 4;
    action["clear"] = 5;
    action["exit"]  = 6;

    while(!on.eof()){
        getline(on, s);
        std::size_t found_pus = s.find("push");
        if (found_pus!=std::string::npos){
            std::size_t found_sp = s.find(' ', 0);
            com = s.substr(0,found_sp);
            el = stoi(s.substr(found_sp+1, s.size()));
        }
        else com = s;

        switch (action[com]){
            case(0):
                out << std::endl;
                break;
            case(1):
                push(L, el, out);
                break;
            case (2): 
                pop(L, out, "yes");
                break;
            case (3):
                front(L, out);
                break;
            case(4):
                size(L, out);
                break;
            case(5):
                clear(L, out);
                break;
            case(6):
                exit(out);
                break;
        }
    }
    printQueue(L);
    return 0;
}