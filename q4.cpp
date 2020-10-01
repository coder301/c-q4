#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next = NULL;
    }
};
Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head == NULL){
        head = newNode;
        tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
Node* midpoint_linkedlist(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while(fast!= NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    Node* head = takeInput();
    print(head);
    Node* mid = midpoint_linkedlist(head);
    cout<<endl;
    cout<<"mid point is  " << mid->data;

}
