// Delete Node at any position...
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
void deleteNodeAtposition(int pos){
	// delete korar age to jante hobe j node null kina . tarpor to delete kora jabe
	if(head == NULL){
        cout<<"list is empty , nothing to delete"<<endl;
        return;
    }
    Node *temp = head;
    if(pos == 1){
    	head = temp -> next;
    	delete temp;
    	return;
    }
    for(int i = 1; temp != NULL && i<pos -1; i++){
    	temp = temp -> next;
    	if(temp == NULL || temp -> next == NULL){
    		cout<<pos<<"does not exits in the list"<<endl;
    		return;
    	}
    	
    } 

    Node *next = temp ->next->next;
    delete temp-> next;
    temp -> next = next;

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

    deleteNodeAtposition(2);
    print();
    return 0;
}