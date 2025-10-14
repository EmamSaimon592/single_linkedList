
//insert at the first position 
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

    print();  // Output: 10 -> 5 -> 1 -> NULL
    return 0;
}

