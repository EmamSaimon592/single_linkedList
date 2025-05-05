//Delete first Node...
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
void deleteFirstNode(){
    if(head == NULL){
        cout<<"list is empty , nothing to delete"<<endl;
        return;
    }

    Node *temp = head;
    head = head -> next;
    delete temp;
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
    print();

    deleteFirstNode();
    print();



    return 0;
}
//output will be =>
// Data elements in a single linked list are: 
// 20 -> 15 -> 10 -> 5 -> 1 -> NULL
// Data elements in a single linked list are: 
// 15 -> 10 -> 5 -> 1 -> NULL
