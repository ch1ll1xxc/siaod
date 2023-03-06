#include <iostream>

//realise func to make list *tick*
//realise func to output *tick*
//realise func to make list that includes info both of 2 lists
//here i need func input_node and find
//realise func to delete node before node w info < 0 in L2
//here i need func delete and find
//realise funs to input node before node that %2 = 1 in L1
//here idk what i need


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

void more_push_backs(list& list) {
    int amount_push_backs;
    std::cin >> amount_push_backs;
    for (unsigned i = 0; i < amount_push_backs; i++) {
        float _data;
        std::cout << "Enter data: ";
        std::cin >> _data;
        push_back(list, _data);
    }
}

void input_node(list& list, Node& node) {
    Node* p = new Node(node.data);
    if (isEmpty(list)) {
        list.first = p;
        list.last = p;
        return;
    }
    list.last->next = p;
    list.last = p;
}

int count(list& list) {
    Node* p = list.first;
    int c = 0;
    while (p) {
        c++;
        p = p->next;
    }
    return c;
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

//Node* find(list& list,Node& node) {
//    float _data = node.data;
//    if (isEmpty(list)) return;
//    Node* p = list.first;
//    while (p && p->data != _data) p = p->next;
//    return (p && p->data == _data) ? p : nullptr;
//}

void GeneralList(list& list1, list& list2, list& listGen) {
    if (isEmpty(list1) or isEmpty(list2)) return;
    if (count(list1) >= count(list2)) Node* p = list1.first;
    else Node* p = list2.first;
}

int main() {
    list L1;
    list L2;
    list LGen;
    more_push_backs(L1);
    more_push_backs(L2);
    output(L1);
    output(L2);
    std::cout << "Amount of elements in L1" << count(L1) << std::endl;
    std::cout << "Amount of elements in L2" << count(L2) << std::endl;

    return 0;
}
