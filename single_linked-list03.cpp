//insert at any  position 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at the beginning
void insert(int n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertAtend(int n){
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    // If the list is empty
    if(head == NULL){
        head = newNode;
        return; // Exit the function here
    }

    // Traverse to the last node
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    // Append at the end
    temp->next = newNode;
}

//insert at any position  code is here :
void insertAtPosition(int pos , int n){
    Node *newNode = new Node;
    newNode -> data = n;

    if(pos == 1){
        newNode -> next = head;
        head = newNode;
    }
    // for Traversing 
     Node* temp = head;
     for(int i = 1; i<pos -1 && temp!= NULL; i++){
        temp = temp -> next;
     }
     if(temp == NULL){
        cout<<"invalid position "<<endl;
     }
     newNode -> next = temp -> next;
     temp -> next = newNode;


}

// Print the list
void print() {
    cout << "Data elements in a single linked list are: " << endl;
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    insert(1);
    insert(5);
    insert(10);
    insert(15);
    insert(20);



    // print(); // Should print 20 -> 15 -> 10 -> 5 -> 1 -> NULL

    insertAtPosition(4, 4);
    print(); //20 -> 15 -> 10 -> 4 -> 5 -> 1 -> NULL

    // insertAtend(25);
    // print(); // Should print 20 -> 15 -> 10 -> 5 -> 1 -> 25 -> NULL

    return 0;
}
