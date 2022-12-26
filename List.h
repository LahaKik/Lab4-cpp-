#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct Node
{
	T field;
	Node* next = nullptr;
	Node* prev = nullptr;
	
};

template <typename T>
class List
{
	Node<T>* Head, * Tail;

	Node<T>* Search(int index) {
		Node<T>* temp = Head;
		if (index < 0 || index > Count) throw 1;
		for (int i = 0; i < index; i++)
		{
			if (temp != nullptr && temp->next != nullptr)
				temp = temp->next;
			else throw 1;
		}
		return temp;
	}

public:
	List<T>() : Head(nullptr), Tail(nullptr) {};

	int Count = 0;

	T* Get(int index) {
		Node<T>* temp = Head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return &(temp->field);
	}

	void Add(T field)
	{
		Node<T> *temp = (Node<T> *) malloc(sizeof(Node<T>));
		temp->field = field;
		temp->next = nullptr;
		if (Head != nullptr) {
			temp->prev = Tail;
			Tail->next = temp;
			Tail = temp;
		}
		else {
			temp->prev = nullptr;
			Head = Tail = temp;
		}
		Count++;
	};

	void AddAt(T field, int index) {
		Node<T>* temp = new Node<T>();
		Node<T>* insertPos = Search(index);
		if (insertPos == nullptr) {
			temp->prev = nullptr;
			Head = Tail = temp;
		}
		else if (insertPos == Head) {
			insertPos->prev = temp;
			temp->next = insertPos;
			temp->prev = nullptr;
			Head = temp;
		}
		else if (insertPos == Tail) {
			insertPos->next = temp;
			temp->next = nullptr;
			temp->prev = insertPos;
			Tail = temp;
		}
		else
		{
			temp->next = insertPos;
			temp->prev = insertPos->prev;
			insertPos->prev->next = temp;
			insertPos->prev = temp;
		}
		temp->field = field;
		Count++;
	}

	void RemoveAt(int index) {
		Node<T>* removePos = Search(index);
		if (removePos == Head) {
			if (removePos->next != nullptr) {
				removePos->next->prev = nullptr;
				Head = removePos->next;
			}
		}
		else if (removePos == Tail) {
			removePos->prev->next = nullptr;
			Tail = removePos->prev;
		}
		else {
			removePos->next->prev = removePos->prev;
			removePos->prev->next = removePos->next;
		}
		delete removePos;
		Count--;
	}

	void Show() {
		Node<T>* temp = Head;

		while (temp != nullptr)
		{
			cout << temp->field << endl;
			temp = temp->next;
		}
	}

	string ToString() {
		string str = "";
		for (int i = 0; i < Count; i++)
		{
			T sym = *Get(i);
			str += sym;
		}
		return str;
	}

	int ToInt() {
		int Num = static_cast<int>(*Get(0));
		for (int i = 1; i < Count; i++)
		{
			Num *= 10;
			Num += static_cast<int>(*Get(0));
		}
		return Num;
	}

	bool ToBool() {
		string str = "";
		for (int i = 0; i < 4; i++)
		{
			str += *Get(i);
		}
		if (str == "true")
			return true;
		return false;
	}

	void Clear()
	{
		while (Head != nullptr)
		{
			Tail = Head->next;
			delete Head;
			Head = Tail;
		}
		Head = nullptr;
		Tail = nullptr;
		Count = 0;
	};
};
