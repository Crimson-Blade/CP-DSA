#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
void insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}
void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//delete
void Delete(int n)
{
    Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}
int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    int n;
    cin >> n;
    Delete(n);
    print();
    return 0;
}