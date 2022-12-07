/**
 * Inorder traversal of BST always returns values in ascending order
*/

#include <bits/stdc++.h>
using namespace std;
class node
{
  public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
class binary_tree{
  public:
    node* root;
    binary_tree(){
        root = NULL;
    }
    //init
    void append(int d){
        node *p, *curr, *prev;
        p = new node(d);
        if(!root){
            root = p;
            return;
        }
        curr = root;
        prev = NULL;
        while(curr){
            prev = curr;
            curr = (d < curr->data)?curr->left:curr->right;
        }
        if(d < prev->data) prev->left = p;
        else prev->right = p;
    }
    //traversal methods
    void inorder(node* ptr ){
        if(ptr){
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);

        }
    }
    void inorder(){
        node * ptr = root;
        if(ptr){
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);

        }
    }
    // searching
    // iterative method
    node* iterative_search(int d){
        node* trav = root;
        while(trav!=NULL && d!=trav->data){
            trav = (d<trav->data)?trav->left:trav->right;
        }
        return trav;
    }
    int min_element(){
        node* trav = root;
        if(!trav) return NULL;
        while(trav->left)
            trav = trav->left;
        return trav->data;
    }
    int max_element(){
        node* trav = root;
        if(!trav) return NULL;
        while(trav->right)
            trav = trav->right;
        return trav->data;
    }
};
int main(){
    binary_tree bt;
    for(int i=0;i<5;i++){
        int temp; cin>>temp;
        bt.append(temp);
    }
    bt.inorder();
    cout<<"Enter element to Search\n";
    int ele;
    cin>>ele;
    if(bt.iterative_search(ele)) cout<<"Found\n";
    else cout<<"Not Found\n";
    cout<<"Min Element\n";
    cout<<bt.min_element()<<endl;
    cout<<"Max Element\n";
    cout<<bt.max_element()<<endl;
}