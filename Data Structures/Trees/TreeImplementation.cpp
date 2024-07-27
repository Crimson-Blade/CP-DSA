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
    //cout<<"Enter Data(-1 for no data): ";
    cin>>x;
    if(x == "-1") return NULL;
    p=new node();
    p->data = x;

    //cout<<"Enter left child of "<<x<<": ";
    p->left = create_binary_tree();

    //cout<<"Enter right child of "<<x<<": ";
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
  void levelorder(){
    /**
     * @brief 
     * Create an empty queue q and push root in q.
      Run While loop until q is not empty. 
      Initialize temp_node = q.front() and print temp_node->data.
      Push temp_node’s children i.e. temp_node -> left then temp_node -> right to q
      Pop front node from q.
     */
    queue<node*> q;
    node *trav = root;
    q.push(trav);
    while(!q.empty()){
      node *curr = q.front();
      cout<<curr->data<<" ";
      q.pop();
      //enque left followed by right child
      if(curr->left)
      q.push(curr->left);
      if(curr->right)
      q.push(curr->right);
    }
  }
};
int main(){
    freopen("input.txt","r",stdin);
    binary_tree bt;
    bt.inorder();
    cout<<endl;
    bt.levelorder();
}