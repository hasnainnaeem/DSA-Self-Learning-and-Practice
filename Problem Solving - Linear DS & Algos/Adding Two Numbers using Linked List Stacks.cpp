/*
 * Adding two numbers in C++ using Stacks implemented by Singly Linked List
 * Written by Muhammad Hasnain Naeem
 * Dated: 10/13/2018
 */
#include <iostream>
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
            //if found insert
            if (i == loc - 1)
            {
                Node *temp = new Node(value, itr->next);
                itr->next = temp;
                return 0;
            }
		//else iterate further
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
};


int size = 10; //Select Max number of digits in Numbers which are being added

int sepDigits(int num, int* array){
    int divisor = 1;

    for(int i = 0; i < size-1; i++){
        divisor *= 10;
    }

    for(int i = 0; i < size; i++){
        array[i] = (num/divisor)%10;
        divisor /= 10;
    }
}

int main()
{
    int num = 0;
    cout << "Enter 1st number: ";
    cin >> num;
    int firstNum[size];
    sepDigits(num, firstNum);

    cout << "Enter 2nd number: ";
    cin >> num;
    int secondNum[size];
    sepDigits(num, secondNum);

    cout << endl;
    /*
     * Operations using stack start from here
     */
    SinglyLinkedList stack1;
    for(int i = 0; i < size ; i++)
        stack1.push(firstNum[i]);


    SinglyLinkedList stack2;
    for(int i = 0; i < size ; i++)
        stack2.push(secondNum[i]);


    cout << endl;
    SinglyLinkedList resStack;


    int result = 0;
    int carry = 0;

    for(int i =0; i < size; i++){

        result = stack1.pop() + stack2.pop() + carry;

        if (result > 9)
            carry = 1;

        else
            carry = 0;

        resStack.push(result%10);
    }


    cout << "Sum:" << "\t";
    cout << carry;
    for(int i =0; i < size; i++){
        cout << resStack.pop();
    }
    getchar();
}


