#include <bits/stdc++.h>
using namespace std;
class node
{
  public:
    string data;
    node* left;
    node* right;
};
class binary_tree{
  public:
  node* root;
  binary_tree(){
    root = create_binary_tree();
  }
  node * create_binary_tree(){
    node *p;
    string x;
    cout<<"Enter Data(-1 for no data): ";
    cin>>x;
    if(x == "-1") return NULL;
    p=new node();
    p->data = x;

    cout<<"Enter left child of "<<x<<": ";
    p->left = create_binary_tree();

    cout<<"Enter right child of "<<x<<": ";
    p->right = create_binary_tree();

    return p;
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
};
int main(){
    binary_tree bt;
    bt.inorder();
}