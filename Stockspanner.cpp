/*
#include<iostream>
using namespace std;
template <typename T>
class Abstract
{
public:
	virtual void push(T value) = 0;
	virtual void pop() = 0;
	virtual T top() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;

};
template <typename T>
class Stack :public Abstract<T>
{
private:
	T* arr;
	int topIndex;
	int size;
public:
	Stack(int s)
	{
		size = s;
		arr = new T[size];
		topIndex = -1;

	}
	bool isFull()
	{
		return topIndex == size - 1;
	}
	bool isEmpty()
	{
		return topIndex == -1;
	}
	void push(T value)
	{
		if (isFull())
		{
			cout << "Stack is already full" << endl;
		}
		else
		{
			topIndex++;
			arr[topIndex] = value;

		}
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is already empty" << endl;
		}
		else
		{
			topIndex--;

		}
	}
	T top()
	{
		return arr[topIndex];

	}
	~Stack()
	{
		delete []arr;
	}
};
class StockSpanner
{
private:
	Stack<int> priceStack;
	Stack<int> spanStack;
public:
	StockSpanner() :priceStack(10), spanStack(10) {}
	int next(int price)
	{
		int span = 1;
		while (!priceStack.isEmpty() && priceStack.top() <= price)
		{
			span += spanStack.top();
			priceStack.pop();
			spanStack.pop();
		}
		priceStack.push(price);
		spanStack.push(span);
		return span;

	}

};
int main()
{
	StockSpanner s1;
	int prices[] = { 100,80,60,70,60,75,85 };
	int size = 7;
	cout << "Span :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << s1.next(prices[i]) << "\t" ;
	}
	return 0;
}
*/