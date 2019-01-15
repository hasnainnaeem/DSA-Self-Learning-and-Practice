/*
Implementation of Priority Queues using Linked Lists in C++
Written by Muhammad Hasnain Naeem
Dated: 10/9/18
*/

#include <iostream>
using namespace std;

class Node{

public:
    int data;
    int priority;
    Node* next;

    Node(int data, int priority, Node* next = nullptr)
    {
        this->data = data;
        this->priority = priority;
        this->next = next;
    }
};

class Queue {

    Node* head;
    Node* tail;

    int front; //head of queue
    int rear; //tail of queue
    size_t size;

public:

    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }


    bool isEmpty()
    {
        if (tail == nullptr)
            return true;
        else
            return false;
    }

    void enqueue(int val, int prior = 0)
    {
        size++;

        if (head == nullptr)
        {
            head = new Node(val, prior, nullptr);
            tail = head;
        }

        else if (head->priority < prior)
        {
            head = new Node(val, prior, head);
        }

        else
        {
            Node* temp = head;
            // iterate while below condition is true
            while (temp->next != nullptr && temp->next->priority < prior)
            {
                temp = temp -> next;
            }

            // insert new node after iteration
            Node* newNode = new Node(val, prior, temp->next);
            temp->next = newNode;
        }
    }


    int dequeue(){

        Node* temp;
        int val;

        if (!isEmpty())
        {
            size--;
            temp = head;
            head = head->next;


            if (head == nullptr) //Updating tail when last element is deleted
                tail = nullptr;

            val = temp->data;
            cout << endl << "Dequeuing " << val << endl;
            return val;
        }
        return -1;
    }

    void clear() //1 to set all elements to -1 & 2 to delete array
    {
        Node* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            head = temp;
        }
        tail = nullptr;
    }

    int getElement()
    {
        return head->data;
    }

    void displayValues()
    {
        if (head == nullptr)
            cout << "None" << endl;

        else {
            Node* temp = head;

            cout << "Displaying queue contents in prioritized order:" << endl;
            while (temp != nullptr)
            {
                cout << temp->data << "\t" << temp->priority << endl;
                temp = temp->next;
            }
        }
    }
};


int main() {
    Queue queue;

    queue.enqueue(0);
    queue.enqueue(1,1);
    queue.enqueue(2,2);
    queue.enqueue(1, 1);

    queue.displayValues();

    queue.clear();
    queue.dequeue();

    queue.displayValues();

    getchar();
    return 0;
}