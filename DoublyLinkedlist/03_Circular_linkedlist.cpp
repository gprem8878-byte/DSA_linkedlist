#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
int main()
{
    Node* Head = NULL;
    Node * curr = NULL;
    Node* tail = NULL;

    int arr[] = {1,2,3,4,5,6};
    for(int i=0;i<6;i++){
       if(Head == NULL){
            Head = new Node(arr[i]);
            curr = Head;
            // tail = Head;
        }
        else{
        curr->next = new Node(arr[i]);
        tail = curr;
        curr = curr->next;
        curr->prev = tail;
        }
    }
    curr->next = Head;
    Head->prev = curr;
    tail = Head;
    do{
        cout << tail->data << " ";
        tail = tail->next;
    }while(tail != Head);
    return 0;
}