// Create a Doubly linked list with n nodes. Create a function to delete nth node from last. Embed a second list at nth
// position of first list. Also create a function to remove duplicates
// from the list.
#include <iostream>
using namespace std;
class dll {
    public:
    class node {
        public:
        int data;
        node *next, *prev;
        node(){
            next = prev = NULL;
        }
        node(int d){
            data = d;
            next = prev = NULL;
        }
    };
    node *head, *tail;
    dll(){
        head = tail = NULL;
    }
    int size(){
        int count = 0;
        node *trav = head;
        while(trav){
            count++;
            trav = trav->next;
        }
        return count;
    }
    void insertAtIndex(int index){
        int d;
        cout<<"Enter data: ";
        cin>>d;
        node *temp = new node(d);
        if(head == NULL){
            head = tail = temp;
        }
        else if(index == 0){
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else{
            node *trav = head;
            for(int i = 0; i < index - 1; i++){
                trav = trav->next;
            }
            temp->next = trav->next;
            temp->prev = trav;
            trav->next = temp;
            if(temp->next != NULL){
                temp->next->prev = temp;
            }
            else{
                tail = temp;
            }
        }
    }
    void deleteAtIndex(int index){
        if(head == NULL){
            cout<<"List is empty\n";
        }
        else if(index == 0){
            node *temp = head;
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
            else{
                tail = NULL;
            }
            delete temp;
        }
        else{
            node *trav = head;
            for(int i = 0; i < index - 1; i++){
                trav = trav->next;
            }
            node *temp = trav->next;
            trav->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = trav;
            }
            else{
                tail = trav;
            }
            delete temp;
        }
    }
    void deleteFromLast(int n){
        deleteAtIndex( size() - n);
    }
    void removeDuplicates(){
        node *trav = head;
        while(trav){
            node *trav2 = trav->next;
            while(trav2){
                if(trav2->data == trav->data){
                    node *temp = trav2;
                    trav2->prev->next = trav2->next;
                    if(trav2->next != NULL){
                        trav2->next->prev = trav2->prev;
                    }
                    else{
                        tail = trav2->prev;
                    }
                    trav2 = trav2->next;
                    delete temp;
                }
                else{
                    trav2 = trav2->next;
                }
            }
            trav = trav->next;
        }
    }
    void display(){
        node *trav = head;
        while(trav){
            cout<<trav->data<<" ";
            trav = trav->next;
        }
        cout<<endl;
    }
};
int main(){
    dll l1;
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        l1.insertAtIndex(i);
    }
    l1.removeDuplicates();
    l1.display();
    return 0;
}