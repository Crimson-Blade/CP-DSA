#include <iostream>
#include <stack>
using namespace std;
class node {
    public:
    char data;
    node *left, *right;
    node(char d){
        data = d;
        left = right = NULL;
    }
};
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
//create tree from postfix using stack
node *createTreeFromPostfix(string postfix){
    stack<node *> st;
    node *t, *t1, *t2;
    for(int i = 0; i < postfix.length(); i++){
        if(!isOperator(postfix[i])){
            t = new node(postfix[i]);
            st.push(t);
        }
        else{
            t = new node(postfix[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->right = t1;
            t->left = t2;
            st.push(t);
        }
    }
    t = st.top();
    st.pop();
    return t;
}
//create tree from prefix using stack
node *createTreeFromPrefix(string prefix){
    stack<node *> st;
    node *t, *t1, *t2;
    for(int i = prefix.length() - 1; i >= 0; i--){
        if(!isOperator(prefix[i])){
            t = new node(prefix[i]);
            st.push(t);
        }
        else{
            t = new node(prefix[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->left = t1;
            t->right = t2;
            st.push(t);
        }
    }
    t = st.top();
    st.pop();
    return t;
}
// precedence of operators
int prec(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
//convert infix to postfix
string infixToPostfix(string infix){
    infix = '(' + infix + ')';
    stack<char> s;
    string postfix = "";
    for(int i=0;i<infix.length();i++){
        if(isOperator(infix[i])){
            while(prec(infix[i])<=prec(s.top())){
                postfix+=s.top();s.pop();
            }
            s.push(infix[i]);
        }
        else if(infix[i] == '(')
            s.push('(');
        else if(infix[i] == ')'){
            while(s.top() != '('){
                postfix+=s.top();s.pop();
            }
            s.pop();
        }
        else{
            postfix+=infix[i];
        }
    }
    return postfix;
}

void inorder(node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node *root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main(){
    string postfix,infix;
    cout<<"Enter     expression: ";
    // cin>>postfix;
    // node *root = createTreeFromPostfix(postfix);
    cin>>infix;
    postfix = infixToPostfix(infix);
    node *root = createTreeFromPostfix(postfix);
    cout<<"Inorder traversal of tree / Infix expression : ";
    inorder(root);
    cout<<"Preorder traversal of tree / Prefix expression : ";
    preorder(root);
    cout<<"Postorder traversal of tree / Postfix expression : ";
    postorder(root);
}