#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>

class Stack {
private:
    int top;
    int size;
    int capacity;
    T* stack = new T[10];
public:
    Stack() {
        this->top = -1;
        this->size = 0;
        this->capacity = 1;
    }
    // Push elements onto the stack
    void push(T value) {
        if (isFull()) {
            capacity++;
            T* temp = new T[capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = T(); // Allocate memory for temp
            }
            for (int i = 0; i < size; i++) {
                temp[i] = stack[i]; // Copy the values from the original stack to temp
            }
            delete[] stack; // Free memory for the old array
            stack = temp; // Copy temp to stack
        }
        top++; // Increment the index position
        stack[top] = value; // Assign a new value to that position in the stack
        size++;
    }
    // Pop the top element of the stack
    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            T popValue = stack[top]; // Store the value that will be removed
            stack[top] = T();            // removed the value by assigning it to 0
            top--;                   // Decrement the index position
            return popValue;         // Return the removed value
        }
    }
    // Peek the top element of the stack
    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        else {
            return stack[top];
        }
    }
    // Check if the stack is full
    bool isFull() {
        if (this->top == size) {
            return true;
        }
        else {
            return false;
        }
    }
    // Check if the stack is empty
    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    // Return the number of elements in the stack
    int count() {
        return (top + 1);
    }
    // Display all the values in the stack
    void display() {
        cout << "All the values in the stack are: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};