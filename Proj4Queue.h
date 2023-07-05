#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>

class Queue {
private:
    T* queue; // Queue array
    int front;
    int back;
    int capacity; // Capacity of the queue
    int size; // Current number of elements in the array
public:
    Queue(int capacity) {
        this->front = -1;
        this->back = -1;
        this->capacity = capacity;
        this->size = 0;
        queue = new T[capacity]();
    }
    // Add elements to the queue
    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty()) { // If queue is empty, then set rear and front to 0 which is at the start of the queue.
            back = 0;
            front = 0;
            queue[back] = value;
            size++;
        }
        else {
            back++;
            queue[back] = value;
            size++;
        }
    }
    T dequeue() {
        T x; // Variable used to return the removed value
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        else if (front == back) { // Check if front and rear are at the same position and if true, set both of them to -1
            x = queue[front];
            queue[front] = T();
            front = -1;
            back = -1;
            size--;
            return x;
        }
        else {
            x = queue[front];
            for (int i = 0; i < size; i++) {
                queue[i] = queue[i + 1];
            }
            size--;
            return x;
        }
    }
    bool isFull() {
        if (size == capacity) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    int count() {
        return (size);
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << queue[i] << " ";
        }
    }
};