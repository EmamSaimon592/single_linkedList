// Delete last Node...
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
void deleteLastNode(){
	// delete korar age to jante hobe j node null kina . tarpor to delete kora jabe
	if(head == NULL){
        cout<<"list is empty , nothing to delete"<<endl;
        return;
    }

    if(head -> next == NULL){
    	delete head;
    	head = NULL;
    	return;
    }
  Node *temp = head;
  while(temp -> next ->next != NULL){
  		temp = temp ->next;
  }
  delete temp ->next;
  temp -> next = NULL;

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
    print(); //Data elements in a single linked list are: 20 -> 15 -> 10 -> 5 -> 1 -> NULL

    deleteLastNode();
    print(); //Data elements in a single linked list are: 20 -> 15 -> 10 -> 5-> NULL
    return 0;
}

