#include<iostream>
#include<fstream>
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
		delete[]arr;
	}
};
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int maze[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fin >> maze[i][j];
		}
	}
	Stack<int> s(20);
	int i = 0;
	int j = 0;
	if (maze[0][0] == 0)
	{
		fout << "Path Not Found" << endl;
		return 0;
	}
	s.push(0);
	maze[0][0] = -1;
	while (!s.isEmpty())
	{
		int position = s.top();
		i = position / 4;
		j = position % 4;
		if (i == 3 && j == 3)
		{
			break;
		}
		if (i + 1 < 4 && maze[i + 1][j] == 1)
		{
			s.push((i + 1) * 4 + j);
			maze[i + 1][j] = -1;
		}
		else if (j + 1 < 4 && maze[i][j + 1] == 1)
		{
			s.push(i * 4 + j + 1);
			maze[i][j + 1] = -1;

		}
		else
		{
			s.pop();
		}
	}
	if (s.isEmpty())
	{
		fout << "Path not found" << endl;
	}
	else
	{
		for (int a = 0; a < 4; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				if (maze[a][b] == -1)
				{
					fout << "1" << "\t";
				}
				else
				{
					fout << "0" << "\t";
				}
			}
			fout << endl;
		}
	}
	fin.close();
	fout.close();


	return 0;
}