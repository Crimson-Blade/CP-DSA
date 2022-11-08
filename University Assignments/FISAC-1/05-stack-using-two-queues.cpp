#include <iostream>
using namespace std;
// stack using two queues
class queue{
    public:
    int size;
    int arr[100];
    int front;
    int rear;
    queue(){
        size = 100;
        front = -1;
        rear = -1;
    }
    void enqueue(int x){
        if(rear == size-1){
            cout<<"Queue is full"<<endl;
        }
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = x;
        }
        else{
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }
    }
    int peek(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    bool isEmpty(){
        return front == -1 && rear == -1;
    }
};
class stack{
    public:
    queue q1;
    queue q2;
    void push(int x){
        q1.enqueue(x);
    }
    void pop(){
        if(q1.isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
            while(q1.rear != q1.front){
                q2.enqueue(q1.peek());
                q1.dequeue();
            }
            q1.dequeue();
            queue temp = q1;
            q1 = q2;
            q2 = temp;
        }
    }
    int top(){
        if(q1.isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            while(q1.rear != q1.front){
                q2.enqueue(q1.peek());
                q1.dequeue();
            }
            int x = q1.peek();
            q1.dequeue();
            q2.enqueue(x);
            queue temp = q1;
            q1 = q2;
            q2 = temp;
            return x;
        }
    }
    bool isEmpty(){
        if(q1.isEmpty()){
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    return 0;
}
