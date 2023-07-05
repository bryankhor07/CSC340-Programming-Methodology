#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>

class Node {
private:
	int key;
	T data;
public:
	Node* next;
	Node() {
		this->key = 0;
		this->data = T();
		this->next = nullptr;
	}
	Node(int key, T data) {
		this->key = key;
		this->data = data;
	}
	int getKey() {
		return key;
	}
	T getData() {
		return data;
	}
	void setData(T data) {
		this->data = data;
	}
	void setKey(int key) {
		this->key = key;
	}
};

template<class T>

class LinkedList {
private:
	Node<T>* head;
public:
	LinkedList() {
		head = nullptr;
	}
	LinkedList(Node<T>* node) {
		head = node;
	}
	// Check if key exists using key value
	Node<T>* nodeExists(int key) {
		Node<T>* temp = nullptr;
		Node<T>* ptr = head; // ptr stores the address of the head node

		while (ptr != nullptr) {
			if (ptr->getKey() == key) {
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}
	// Append a node to the linked list
	void appendNode(Node<T>* node) {
		if (nodeExists(node->getKey()) != nullptr) { // Check if the node of the key exists
			cout << "Node already exists. Append another node with a different key value." << endl;
		}
		else {
			// This if statement check if there are no existing node and if it is true, then add it as the head node
			if (head == nullptr) {
				head = node;
				cout << "Node appended." << endl;
			}
			else {
				Node<T>* ptr = head; // ptr stores the address of the head node
				// This while loop will keep executing until the next ptr of that current node is equal to NULL.
				// When it is equal to NULL, that means we have reached to the end of the node
				while (ptr->next != nullptr)
				{
					ptr = ptr->next; // stores the address of the next node
				}
				ptr->next = node; // stores the address of the new node in the next node of the previous node.
				cout << "Node appended" << endl;
			}
		}
	}
	// Prepend a node to the linked list
	void prependNode(Node<T>* node) {
		if (nodeExists(node->getKey()) != nullptr) { // Check if the node of the key exists
			cout << "Node already exists. Append another node with a different key value." << endl;
		}
		else {
			node->next = head;
			head = node;
			cout << "Node prepended" << endl;
		}
	}
	// Insert a node after a particular node in the linked list
	// int key is the key value of that particular node that will have a new node added after it
	// Node *node is the new node to be added
	void insertNode(int key, Node<T>* node) {
		Node<T>* ptr = nodeExists(key); // Stores null if no node exist with that key value, otherwise it exists
		if (ptr == nullptr) {
			cout << "No node exists with key value " << key << endl;
		}
		else {
			if (nodeExists(node->getKey()) != nullptr) { // Check if the node of the key exists
				cout << "Node already exists. Append another node with a different key value" << endl;
			}
			else {
				node->next = ptr->next; // Store the pointer of the particular node in the next pointer of the new node to link them
				ptr->next = node;
				cout << "Node inserted." << endl;
			}
		}
	}
	// Delete node by unique key
	void deleteNode(int key) {
		if (head == nullptr) {
			cout << "List is empty." << endl;
		}
		else if (head != nullptr) {
			if (head->getKey() == key) {
				head = head->next;
				cout << "Node unlinked with key value " << key << endl;
			}
			else {
				Node<T>* temp = nullptr;
				Node<T>* previousptr = head;
				Node<T>* currentptr = head->next;
				while (currentptr != nullptr) {
					if (currentptr->getKey() == key) {
						temp = currentptr;
						currentptr = nullptr;
					}
					else {
						previousptr = previousptr->next;
						currentptr = currentptr->next;
					}
				}
				if (temp != nullptr) {
					previousptr->next = temp->next;
					cout << "Node unlinked with key value: " << key << endl;
				}
				else {
					cout << "Node doesn't exist with key value: " << key << endl;
				}
			}
		}
	}
	// Update node by key
	void updateNode(int key, T data) {
		Node<T>* ptr = nodeExists(key); // Pointer to hold the node
		if (ptr != nullptr) {
			ptr->setData(data);
			cout << "Node updated successfully" << endl;
		}
		else {
			cout << "Node doesn't exist." << endl;
		}
	}
	// Printing list
	void print() {
		if (head == nullptr) { // If head is null, that means the list is empty
			cout << "No nodes in Singly Linked List" << endl;
		}
		else {
			cout << "Linked List values: " << endl;
			Node<T>* temp = head; // Temporary pointer that stores the head

			while (temp != nullptr) { // Print the list until it reaches the end
				cout << "(" << temp->getKey() << ", " << temp->getData() << ") --> " << endl;
				temp = temp->next; // This line of code set the pointer to the next node
			}
		}
	}
};