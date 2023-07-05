#pragma once
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

template<class T>
class Heap {
private:
	T* arr; // Array of elements
	int capacity; // Capacity of the array
	int size; // Current number of elements in the array
public:
	Heap(int capacity) { // Constructor
		this->size = 0;
		this->capacity = capacity;
		arr = new T[capacity];
	}
	int getCapacity() {
		return capacity;
	}
	void setCapacity(int capacity) {
		this->capacity = capacity;
	}
	int getSize() {
		return size;
	}
	void setSize(int size) {
		this->size = size;
	}
	int getIndexOfParentNode(int index) { // Returns the index of parent node
		return (index - 1) / 2;
	}
	int getIndexOfLeftNode(int index) { // Returns the index of left node
		return (2 * index + 1);
	}
	int getIndexOfRightNode(int index) { // Returns the index of right node
		return (2 * index + 2);
	}
	T getMinimum() { // Returns the minimum value
		return arr[0];
	}
	T extractMin() { // Removes the minimum value from the heap
		if (size <= 0) {
			return T();
		}
		if (size == 1) {
			size--;
			return arr[0];
		}
		T root = arr[0];
		arr[0] = arr[size - 1];
		size--;
		heapify(0);
		return root;
	}
	void insertValue(T value) { // Insert new value
		if (size == capacity) {
			cout << "Heap is full" << endl;
			return;
		}

		size++;
		int i = size - 1;
		arr[i] = value; // Insert the new value

		// Rearrange the heap according to the rules
		while (i != 0 && arr[getIndexOfParentNode(i)] > arr[i]) {
			T temp = arr[i];
			arr[i] = arr[getIndexOfParentNode(i)];
			arr[getIndexOfParentNode(i)] = temp;
			i = getIndexOfParentNode(i);
		}
	}
	void decreaseValue(int index, T value) { // Decrease the value
		arr[index] = value;
		while (index != 0 && arr[getIndexOfParentNode(index)] > arr[index]) {
			T temp = arr[index];
			arr[index] = arr[getIndexOfParentNode(index)];
			arr[getIndexOfParentNode(index)] = temp;
			index = getIndexOfParentNode(index);
		}
	}
	void deleteKey(int index) {
		decreaseValue(index, T());
		extractMin();
	}
	void heapify(int index) {
		int left = getIndexOfLeftNode(index);
		int right = getIndexOfRightNode(index);
		int smallest = index;
		if (left < size && arr[left] < arr[index]) {
			smallest = left;
		}
		if (right < size && arr[right] < arr[smallest]) {
			smallest = right;
		}
		if (smallest != index) {
			T temp = arr[index];
			arr[index] = arr[smallest];
			arr[smallest] = temp;
			heapify(smallest);
		}
	}
	void searchValue(T value) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == value) {
				cout << "Value exists!" << endl;
				return;
			}
		}
		cout << "Value doesn't exist." << endl;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int getHeight() {
		return ceil(log2(size + 1)) - 1;
	}
};