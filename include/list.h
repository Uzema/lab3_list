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
	};

	Node* first;

public:

	List();
	List(int n, T deflt = T());
	~List();
	List(const List&);
	List& operator=(const List&);
	void print();
	T& operator[](int index);
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

}

template <class T>
inline List<T>::List(const List&) {

}

template <class T>
inline List<T>& List<T>::operator=(const List<T>&) {

}

template <class T>
inline void List<T>::print() {

}

template <class T>
inline T& List<T>::operator[](int index) {

}

template <class T>
inline List<T>::Node* List<T>::insert(T value, List<T>::Node* prev) {

}

template <class T>
inline List<T>::Node* List<T>::insert_front(T value) {

}

template <class T>
inline List<T>::Node* List<T>::erase(List<T>::Node* prev) {

}

template <class T>
inline List<T>::Node* List<T>::erase_front() {

}

#endif