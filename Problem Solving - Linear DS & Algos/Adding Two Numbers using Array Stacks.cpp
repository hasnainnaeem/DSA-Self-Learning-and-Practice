/*
 * Adding two numbers in C++ using Stacks implemented using Arrays
 * Written by Muhammad Hasnain Naeem
 * Dated: 10/13/2018
 */
#include <iostream>
using namespace std;

#define STACKSIZE 100

class Stack {
private:
    int array[STACKSIZE];
    int currSize;
public:
    Stack(){
        currSize = 0;
    }

    void display() {
        for(int i = 0; i < currSize; i++)
            cout << array[i] << "\t";
        cout << endl;
    }

    int peek(){
        return array[currSize-1];
    }


    int pop(){
        if (currSize == 0){//list is empty
            return -1;
        }

        else{
            currSize--;
            return array[currSize];
        }
    }

    void push(int val){
        if(currSize >= STACKSIZE){
            return; //Stack is full
        }

        else{
            array[currSize] = val;
            currSize++;
        }
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
    Stack stack1;
    for(int i = 0; i < size ; i++)
        stack1.push(firstNum[i]);


    Stack stack2;
    for(int i = 0; i < size ; i++)
        stack2.push(secondNum[i]);


    cout << endl;
    Stack resStack;
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


