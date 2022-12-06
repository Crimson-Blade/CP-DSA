/**
 * Read a 2D Matrix
 * Represent sparse matrix in SLL
 * contruct another SLL to hold the transpose (Row-wise order should be maintained)
 * Display contents of both lists
*/

#include <iostream>
using namespace std;
class node{
    public:
    int r,c,v;
    node* next;
    node(int r, int c, int v){
        this->r = r;
        this->c = c;
        this->v = v;
        next = NULL;
    }
};

class LLS {
    public:
    node* head = NULL;
    void append(int r, int c, int v){
        node* t = new node(r,c,v);
        node* trav = head;
        if(head == NULL){
            head = t;
        }
        else{
        while(trav->next)
            trav = trav->next;
        trav->next = t;
        }
    }
    void display(){
        node* trav = head;
            cout<<"r c v"<<endl;
        while(trav){
            cout<<trav->r<<" "<<trav->c<<" "<<trav->v<<endl;
            trav = trav->next;
        }
    }
    void incrementCount(){
        head->v ++;
    }
    void transpose(){
        node* trav;
        trav = head;
        while(trav){
            int temp;
            temp = trav->r;
            trav->r = trav->c;
            trav->c = temp;
            trav = trav->next;
        }
        sort();
    }
    void sort(){
        node* trav1, *trav2;
        if(!head) return;
        trav1 = head->next;
        while(trav1){
            trav2 = trav1->next;
            while(trav2){
                if(trav2->r < trav1->r){
                    int temp;
                    temp = trav1->r;
                    trav1->r = trav2->r;
                    trav2->r = temp;
                    temp = trav1->c;
                    trav1->c = trav2->c;
                    trav2->c = temp;
                    temp = trav1->v;
                    trav1->v = trav2->v;
                    trav2->v = temp;
                }
                trav2 = trav2->next;
            }
                trav1 = trav1->next;
        }
    }
};
int main(){
    LLS lls;
    cout<<"Input MxN"<<endl;
    int m,n,val;
    cin>>m>>n;
    lls.append(m,n,0);
    cout<<"Input Values"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>val;
            if(val != 0) {
                lls.append(i,j,val);
                lls.incrementCount();
            }
        }
    }
    lls.display();
    lls.transpose();
    lls.display();
}
