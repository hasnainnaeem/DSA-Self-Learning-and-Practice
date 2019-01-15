/*
Implementation of Priority Queues using Linked Lists in C++
Written by Muhammad Hasnain Naeem
Dated: 10/9/18
*/

#include <iostream>
using namespace std;

#define SIZE 10

class Queue {

    int data[SIZE];
    int prior[SIZE];
    int front; //head of queue
    int rear; //tail of queue
    size_t len;

public:

    Queue()
    {
        front = -1;
        rear = -1;

        for(int i = 0; i < SIZE; i++)
            data[i] = -1;
    }


    bool isEmpty()
    {
        if(front == -1)
            return true;
        return false;
    }

    bool isFull(){
        if(rear+front == SIZE -1 || front == rear+1)
            return true;
        else
            return false;
    }

    void enqueue(int val, int priority = 0)
    {
        if(isFull()){
            return; //Can't insert, queue is full
        }
        else {
            len++;

            if (rear == SIZE - 1)
                rear = 0;

            else
                rear++;

            data[rear] = val;
            prior[rear] = priority;

		//imp
            if (front == -1)
                front = 0;
        }
    }


    int dequeue(){

       if(isEmpty())
           return -1;
        len--;
       int val = data[front];
       if(front == rear){
           front = -1;
           rear = -1;
       }
       else if(front == SIZE-1){
           front = 0;
       }
       else
           front++;

       return val;
    }

    void clear() //1 to set all elements to -1 & 2 to delete array
    {
        front = -1;
        rear = -1;
    }

    int peek()
    {
        return data[front];
    }

    void displayValues() {
        if (!isEmpty()) {
            int ftemp = front;
            int rtemp = rear;

            cout << "Displaying List:" << endl;

            if (rear > front) {
                for (int i = front; i <= rear; i++) {
                    cout << data[i] << "\t";
                }
            } else {
                while (true) {
                    cout << data[front] << endl;
                    front++;
                    if (front == SIZE - 1)
                        front = 0;
                    if (front == rear + 1)
                        break;
                }
            }

            cout << endl;
        }

        else{
            cout << "Queue is empty." << endl;
        }
    }

    void displayAll(){
        cout << "Displaying All:" << endl;
        for(int i =0; i < SIZE; i++){
            cout << data[i] << "\t";
        }
        cout << endl;
    }
};


int main() {
    Queue queue;

    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.displayValues();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.displayValues();

    getchar();
    return 0;
}