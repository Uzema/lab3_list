#ifndef __List_H__
#define __List_H__

#include <iostream>

using namespace std;

template <class T>
class List {

	struct Node {
		T data;
		Node* next;

		Node() {
			T data = 0;
			Node* next = nullptr;
		}

		Node(T value, Node* next) {
			data = value;
			next = next;
		}
	};

	Node* first;

public:

	List();
	List(int n, T deflt = T());
	~List();
	List(const List&);
	List& operator=(const List& other);
	void print();
	T& operator[](int index);
	Node* find(T value);
	Node* get_first();
	size_t size();
	Node* insert(T value, Node* prev);
	Node* insert_front(T value);
	Node* erase(Node* prev);
	Node* erase_front();

};

template <class T>
inline List<T>::List() {
	Node* first = new Node;
}

template <class T>
inline List<T>::List(int n, T deflt = T()) {
	if (n == 0) return;
	first = new Node(T(), nullptr);

	Node* current = first;

	for (int i = 1; i < n; i++) {
		Node* tmp = new Node(T(), nullptr);
		current->next = tmp;
		current = current->next;
	}
}

template <class T>
inline List<T>::~List() {
	while (first) {
		Node* second = first->next;
		delete first;
		first = second;
	}
}

template <class T>
inline List<T>::List(const List& other) {
	if (!other->first) {}
	this->first = new Node(other.first->data, nullptr);
	Node* current = first, * ocurrent = other.first;
	while (ocurrent->next) {
		current->next = new Node(ocurrent->next->data);
		current = current->next;
		ocurrent = ocurrent->next;
	}
}

template <class T>//todo
inline List<T>& List<T>::operator=(const List<T>& other) {
	Node* current = first;
	Node* ocurrent = other.first;
	if (this->size() > other.size) {
		while (ocurrent) {
			current->data = other->data;
			current = current->next;
			ocurrent = ocurrent->next;
		}
		current->next = nullptr;
	}
	else { //this->size() <= other.size
		while (ocurrent) {
			current->data = other->data;
			current = current->next;
			ocurrent = ocurrent->next;
		}
	}
}

template <class T>
inline void List<T>::print() {
	Node* current = first;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
}

template <class T> //?is this true
inline T& List<T>::operator[](int index) {
	Node* current = first;
	for (int i = 1; i < index; i++) {
		current = current->next;
	}
	return current->data;
}

template <class T>//think more
inline List<T>::Node* List<T>::find(T value) {
	Node* current = first;
	while (current->data != value) {
		current = current->next;
	}
	return current;
}

template <class T>
inline List<T>::Node* List<T>::get_first() {
	return first;
}

template <class T>
size_t List<T>::size() {
	Node* current = first;
	int size = 0;
	while (current) {
		size += 1;
		current = current->next;
	}
	return size;
}

template <class T>
inline List<T>::Node* List<T>::insert(T value, List<T>::Node* prev) {
	Node* temp = new Node;
	temp->next = prev->next;
	temp->data = value;
	prev->next = temp;
	return temp;
}

template <class T>
inline List<T>::Node* List<T>::insert_front(T value) {
	Node* first_first = new Node;
	first_first->next = first;
	first = first_first->next;
	return first;
}

template <class T>
inline List<T>::Node* List<T>::erase(List<T>::Node* prev) {
	Node* tmp = prev->next;
	if (!prev->next) {
		throw 1;
	}
	prev->next = tmp->next;
	delete tmp;
	return prev->next;

}

template <class T>
inline List<T>::Node* List<T>::erase_front() {
	Node* tmp = first;
	first = tmp->next;
	delete tmp;
	return first;
}

#endif