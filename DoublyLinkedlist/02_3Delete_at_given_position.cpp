#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next;
   Node* prev;
   Node(int value){
      data = value;
      next = NULL;
      prev = NULL;
   }
};

Node *Create_DLL(int arr[],int size ,int index,Node* Back){
    if(index == size)
    return NULL;

    Node *temp = new Node(arr[index]);
    temp->prev = Back;
    temp->next = Create_DLL(arr,size,index+1,temp);
    return temp;
}
int main(){
    Node* head = NULL;

    int arr[] ={1,2,3,4,6};

    head = Create_DLL(arr,5,0,NULL);
    int pos = 3;
    if(pos ==1){
        if(head->next == NULL){
            delete head;
            head = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
    else{
        Node* curr = head;
        while(--pos){
            curr = curr->next;
        }
        if(curr->next==NULL){
            curr->prev->next = NULL;
            delete curr;
        }
        else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }
        
    Node* trav = head;
    while(trav){
        cout << trav->data << " ";
        trav = trav->next;
    }
    return 0;
}