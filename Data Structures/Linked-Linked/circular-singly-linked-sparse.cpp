// Insert:
#include <iostream>
using namespace std;
class circular_queue {
    public:
    class node {
        public:
        int row;
        int col;
        int val;
        node *next;
        node(){
            next = NULL;
        }
        node(int r,int c, int v){
            val = v;
            row = r;
            col = c;
            next = NULL;
        }
    };
    node *head;
    void insert_end(node *t){
        if(head == NULL){
            head = t;
            head->next = head;
        }
        else{
            node *trav = head;
            while(trav->next != head){
                trav = trav->next;
            }
            trav->next = t;
            t->next = head;
        }
    }
    void display(){
        node *trav = head;
        cout<<"Row\tCol\tVal\n";
        do{
            cout<<trav->row<<"\t"<<trav->col<<"\t"<<trav->val<<endl;
            trav = trav->next;
        }while(trav != head);
    }
    void init_sparse(){
        int m,n;
        cout<<"Size of 2D matrix (m,n) \n";
        cin>>m>>n;
        head = new node(m,n,0);
        head->next = head;
        cout<<"Enter Elements: \n";

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp;
                cin>>temp;
                if(temp != 0){
                    node *t = new node(i,j,temp);
                    insert_end(t);
                head->val++;
                }
            }
        }
    }
};
void fast_transpose(){
    
}
int main(){
    circular_queue cq;
    cq.init_sparse();
    cq.display();
}