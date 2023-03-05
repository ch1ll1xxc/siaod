#include <iostream>

//realise func to make list *tick*
//realise func to output *tick*
//realise func to make list that includes info both of 2 lists
//realise func to delete node before node w info < 0 in L2
//realse funs to input node before node that %2 = 1 in L1


struct Node {
    float data;
    Node* next;

    Node(float _data) : data(_data), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}
};

bool isEmpty(list& list) {
    return list.first == nullptr;
}

void push_back(list&list, float _data) {
    Node* p = new Node(_data);
    if (isEmpty(list)) {
        list.first = p;
        list.last = p;
        return;
    }
        list.last->next = p;
        list.last = p;
    }

void input(list& list, Node& node) {
    Node* p = new Node(node.data);
    if (isEmpty(list)) {
        list.first = p;
        list.last = p;
        return;
    }
    list.last->next = p;
    list.last = p;
}

void output(list& list) {
    if (isEmpty(list)) return;
    Node* p = list.first;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

Node* find(list&list, )

void GeneralList(list& list1, list& list2, list& listGen) {
    
}

int main() {
    list L1;
    list L2;
    list LGen;
    return 0;
}