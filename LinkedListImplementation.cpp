#include <iostream>

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    public:
        int length;
        Node *head;
        Node *temp;

        LinkedList();
        ~LinkedList();

        void push(Node **head_ref, int data);
        void insert(Node *prev_node, int data);
        void append(Node **head_ref, int data);
};

void LinkedList::push(Node **head_ref, int data) {
    Node *new_node = new Node();        //allocating node
    new_node->data = data;              //putting data 
    new_node->next = *(head_ref);       //make *next of new node as head
    (*head_ref) = new_node;             //move the head to point to the new node
}

void LinkedList::insert(Node *prev_node, int data) {
    Node *new_node = new Node();
    new_node->data = data;              //putting data
    new_node->next = prev_node->next;   //make next of new_node as next of prev_node
    prev_node->next = new_node;         //move the next of prev_node as new_node
}

void LinkedList::append(Node **head_ref, int data) {
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = data;
    new_node->next = NULL;              //this new node is going to be the last node, so make next of it as NULL

    if (*head_ref == NULL) {            //if the linked list is emtpy, then make the new node as head
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL)           //else traverse till the last node
        last = last->next;

    last->next = new_node;              //change the next of last node
}

int main(int argc, const char *argv[])
{
     
    return 0;
}
