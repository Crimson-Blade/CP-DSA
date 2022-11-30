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
    void dequeue(){
        if(head == NULL){
            cout<<"Queue is empty\n";
        }
        else if(head == tail){
            head = tail = NULL;
        }
        else{
            head = head->next;
            tail->next = head;
        }
    }
    void display(){
        node *trav = head;
        if(head == NULL) return;
        do{
            cout<<trav->data<<" ";
            trav = trav->next;
        }while(trav != head);
        cout<<endl;
    }
    //sort
    void sort(){
        if(head == NULL) return;
        node *trav = head;
        do{
            node *trav2 = trav->next;
            while(trav2 != head){
                if(trav->data > trav2->data){
                    int temp = trav->data;
                    trav->data = trav2->data;
                    trav2->data = temp;
                }
                trav2 = trav2->next;
            }
            trav = trav->next;
        }while(trav != head);
    }
};
class polynomial{
    circular_queue poly;
}