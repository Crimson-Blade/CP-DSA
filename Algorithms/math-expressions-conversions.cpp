// Infix to postfix
// Postfix to Infix
// Infix to prefix
// Prefix to Infix
// Postfix to prefix
// Prefix to postfix

//global stack
#include <iostream>
using namespace std;
#define STACK_SIZE 100
class Stack {
    private:
    int top;
    char arr[STACK_SIZE];
    public:
    Stack(){
        top=-1;
    }
    void push(int elem){
        if(top!=STACK_SIZE-1){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    char pop(){
        if(top!=-1)
            return arr[top--];
        return -1;
    }

    char peek(){
        if(top!=-1)
            return arr[top];
        else{
            return -1;
        }
    }
};
class String_Stack{
    int top;
    string arr[100];
    public:
    String_Stack(){
        top=-1;
    }
    void push(string elem){
        if(top<STACK_SIZE){
            arr[++top]=elem;
        }
        else
            cout<<"Stack Overflow!";
    }
    string pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Underflow!"<<endl;
    }
    string peek(){
        if(top>=0)
            return arr[top];
        cout<<"Underflow!"<<endl;
    }
};
// global priority
int getPriority(char c){
     switch (c){
        case '-':
        case '+':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '$':
        case '^':
            return 3;
            break;
        default:
            return 0;
    }
}
// isAlpha isDigit
bool isAlpha(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    return false;
}
bool isDigit(char c){
    if(c>='0' && c<='9')
        return true;
    return false;
}
// infix to postfix
string infixToPostfix(string infix){
    infix = '(' + infix + ')';
    int l = infix.length();
    string postfix = "";
    Stack s;
    for(int i=0;i<l;i++){
        char curr = infix[i];
        if(isAlpha(infix[i]) || isDigit(infix[i])){
            postfix += infix[i];
        }
        else if (infix[i] == '(')
            s.push('(');
        else if(infix[i] == ')'){
            while(s.peek() != '(')
                postfix += s.pop();
            s.pop();
        }
        else{
            while(getPriority(infix[i]) <= getPriority(s.peek())){
                postfix += s.pop();
            }
            s.push(infix[i]);
        }
    }
    return postfix;
}
// Postfix to Infix
string postfixToInfix(string postfix){
    string infix="";
    String_Stack s;
    for(int i=0;i<postfix.length();i++){
        if(isAlpha(postfix[i]) || isDigit(postfix[i])){
            s.push(string(1,postfix[i]));
        }
        else{
            string op1, op2;
            op1 = s.pop();
            op2 = s.pop();
            string fin = "(" + op2 + postfix[i] + op1 + ")";
            s.push(fin);
        }
    }
    return s.peek();
}
// New function defined to handle brackets
string rev(string output){
    string final;
    int len=output.length();
    for(int i=len-1;i>=0;i--){
        if(output[i]=='('){
            final+=')';}
        else if(output[i]==')'){
            final+='(';}
        else
        {
            final+=output[i];
        }
    }
    return final;
}
// infix to prefix - rev + postfixToinfix(< not <=) + rev
string infixtoPrefix(string infix){
    infix="("+infix+")";
    infix=rev(infix);
    int l=infix.size();
    string output;
    Stack s;
    for(int i=0;i<l;i++){
        if(isalpha(infix[i])||isdigit(infix[i]))
            output+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')'){
            while(s.peek()!='(')
                output+=s.pop();
            s.pop();
        }
        else{
            while(getPriority(infix[i])<getPriority(s.peek()))
                output+=s.pop();
            s.push(infix[i]);
        }
    }
    output=rev(output);
    return output;
}
int main(){
    cout<<infixToPostfix("(A+B)/D")<<endl;
    cout<<postfixToInfix("AB+D/")<<endl;
    cout<<infixtoPrefix("(A+B)/D");
}


