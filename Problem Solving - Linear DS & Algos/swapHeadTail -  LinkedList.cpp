/*
 * Adding two numbers in C++ using Stacks implemented by Singly Linked List
 * Written by Muhammad Hasnain Naeem
 * Dated: 10/13/2018
 */
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {

public:

    int data;
    Node* next = nullptr; //stores address of next node

    Node(int data = 0, Node* ref = nullptr){ //Constructor
        this-> data = data;
        this-> next = ref;
    }

};


class SinglyLinkedList {
private:
    Node *head;
    Node *tail;
    size_t size;

public:

    SinglyLinkedList() { //Constructor
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void createNode(int value) {
        Node *temp = new Node(value);
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
        } else {
            tail->next=temp;
            tail=temp;
        }
    }

    void display() {
        Node *temp;
        temp = head;

        while (temp!=nullptr) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }

    void addToHead(int value)
    {
        Node *temp = new Node(value);

        if (head == NULL && tail == NULL)  //new node
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void addToTail(int value)
    {
        Node *temp = new Node(value);

        if (head == NULL && tail == NULL)  //new node
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    int addToLoc(int value, int loc)
    {
        if (loc == 0)
        {
            addToHead(value);
            return 0;  //success
        }
        else if (loc == size)
        {
            addToTail(value);
            return 0;  //success
        }

        Node *itr = head;
        for (int i = 0; i < size; i++)
        {
            //required location
            if (i == loc - 1)
            {
                Node *temp = new Node(value, itr->next);
                itr->next = temp;
                return 0;
            }
            itr = itr->next;
        }

        return -1; //wrong location

    }

    int access(size_t index){

        if (index == 0){
            return head->data;
        }

        Node* iterator;
        iterator = head;

        for(int i = 0; i < index; i++)       {
            iterator = iterator->next;
        }

        return iterator->data;
    }

    int peek(){
        return head->data;
    }


    int pop(){
        if (head == nullptr){//list is empty
            return -1;
        }

        else{
            Node* temp = head;
            head = head->next;
            int val = temp->data;
            delete(temp);
            size--;
            if(size == 0){
                head = tail = nullptr;
            }
            return val;
        }

    }

    void push(int val){
        addToHead(val);
    }




    int count(Node* node){
        if (node == nullptr)
            return 0;
        else
            return 1 + count(node->next);
    }

    Node* getHead(){
        return head;
    }

    int findVal(Node* node, int val){
        if (val == 4)
            return -1;

        if (node->data == val)
            return 0;

        else
            return 1 + findVal(node->next, val);
    }

    void swapFirstLast(Node* node){
        if (head == nullptr || head->next == nullptr)
            return;

        Node* curr = node;
        Node* prev = nullptr;

        while(curr->next != nullptr){
            prev = curr;
            curr = curr->next;
        }

        Node* first = head;
        Node* last = curr;

        last->next = first->next;
        prev->next = first;
        first->next = nullptr;
        head = last;
        tail = first;
    }
};


int main()
{

    SinglyLinkedList list;
    list.addToTail(0);
    list.addToTail(1);
    list.addToTail(2);
    list.addToTail(3);
    list.addToTail(4);
    list.display();

    cout << endl;

    list.swapFirstLast(list.getHead());
    list.display();

    getchar();
}


