#include <iostream>
using namespace std;
class circular_queue {
    public:
    class node {
        public:
        int data;
        node *next;
        node(){
            next = NULL;
        }
        node(int d){
            data = d;
            next = NULL;
        }
    };
    // head and tail
    node *head, *tail;
    circular_queue(){
        head = tail = NULL;
    }
    void enqueue(int d){
        node *temp = new node(d);
        if(head == NULL){
            head = tail = temp;
            tail->next = head;
        }
        else{
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
    }
};
