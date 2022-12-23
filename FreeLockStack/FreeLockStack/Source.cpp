#include <atomic>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int& data_) {
        data = data_;
    }
};

class lock_free_stack {
public:
    void push(int& data) {
        Node* new_node = new Node(data);
        //Возвратить текущее значение атомарной переменной
        new_node->next = head.load();
        while (!head.compare_exchange_weak(new_node->next, new_node));
    }

    void pop(int& result) {
        Node* old_head = head.load();
        while (!head.compare_exchange_weak(old_head, old_head->next));
        result = old_head->data;
    }

private:
    atomic<Node*> head;
};