#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};

// TO INSERT NEW NODE AT THE END OF LINKEDLIST
void insertAtTail(node* &head, int val){
    node* n = new node(val);

    // CASE 1: WHEN HEAD IS NULL i.e. LINKEDLIST IS EMPTY
    if(head==NULL){
        head = n;
        return;
    }

    // CASE 2: WHEN LINKEDLIST HAS SOME NODES
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

// TO INSERT NEW NODE AT THE START OF LINKEDLIST
void insertAthead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

// TO DELETE FIRST NODE IN LINKEDLIST
void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

// TO DELETE NODE IN LINKEDLIST
void deletion(node* &head,int val){
    // CASE 1: WHEN HEAD IS NULL
    if(head==NULL){
        return;
    }
    // CASE 2: WHEN ONLY ONE NODE IS PRESENT IN LINKEDLIST
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

// TO DISPLAY ELEMENTS OF THE LINKEDLIST
void display(node* head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// TO SEARCH ELEMENT IN LINKEDLIST
bool search(node* head, int key){
    node *temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// TO REVERSE THE LINKEDLIST
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

int main(){
    node *head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAthead(head,1);
    deletion(head,4);
    display(head);
    node* newHead = reverse(head);
    display(newHead);

    return 0;
}