// start the code
// Emam Saimon 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int n) {
    Node* newNode = new Node; // Correct: Node* not int*
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

int search(int key){
    Node *temp = head;
    int pos = 1;

    while(temp!= NULL){
        if(temp -> data == key){
            return pos;
        }

    temp = temp ->next;
    pos++;

    }
    return -1;
}


void print() {
    cout<<"Data elements in a single linked list are : "<<endl;
    Node* temp = head;
    while (temp!= NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main() {
    insert(1);
    insert(5);
    insert(10);
    insert(15);
    insert(20);

    int position = search(10);
    if(position == -1){
        cout<<"element not found in the list "<<endl;       
    }
    else{
        cout<<"element found at position : [ "<< position<< " ]📌 in the list"<<endl;
    }

    return 0;
}

