// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T> class Stack
{
public:
	Stack() {
		pos = 0;
		cout << "Stack initialized" << endl;
	}
	~Stack() {
		delete []stack;
		cout << "Stack Destroyed" << endl;
	}
	void push(T a) {
		stack[pos] = a;
		pos++;
	}
	T pop() {
		pos--;
		return stack[pos];
	}
	T popFirst() {
		T temp = stack[0];
		pos--;
		for (int i = 0; i < pos; i++) {
			stack[i] = stack[i + 1];
		}
		return temp;
	}
	void pushAt(T element,int index) {
		pos++;
		for (int i = pos; i > index; i--) {
			stack[i] = stack[i - 1];
		}
		stack[index] = element;
	}
	void viewStack() {
		cout << "Stack elements" << endl;
			for (int i = 0; i <pos; i++) {
			cout << stack[i] << endl;
		}
	}
private:
	const int size = 100;
	T *stack = new T[size];
	int pos;
};




int main()
{
	Stack<int>integerStack;
	for (int i = 0; i < 10; i++) {
	integerStack.push(i);
	}
	integerStack.viewStack();
	cout <<"pop element "<< integerStack.pop()<<endl;
	cout << "pop element " << integerStack.pop() << endl;
	integerStack.viewStack();
	cout << "pop first element " << integerStack.popFirst() << endl;
	integerStack.viewStack();
	for (int i = 0; i < 10; i++) {
		integerStack.push(i);
	}
	integerStack.viewStack();
	cout << "pop first element " << integerStack.popFirst() << endl;
	integerStack.pushAt(11111, 9);
	integerStack.viewStack();
	system("pause");
    return 0;
}

