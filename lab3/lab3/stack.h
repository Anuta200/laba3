#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <cctype>

//using namespace std;
const int MAX_SZ = 10000;


/*template<class T>
class TStack
{
	T* pMem;
	int MaxSize, Num;

public:

	TStack(int _MaxSize = 10);			
	~TStack() {
		delete[] pMem;
	};
	TStack(const TStack& s);			

	int GetSize() {
		return MaxSize;
	};					
	int GetStartIndex() {
		return Num;
	};


	TStack& operator=(const TStack<T>& s); 
	bool operator==(const TStack& s) const;		
	bool operator!=(const TStack& s) const;		

	T Pop();
	void Push(T val);						
	bool Check(std::string str);
	void Clear() {
		Num = -1;
	};

	T Top() const;						
	bool Empty() const {
		return (Num == -1);
	};						
	bool Full() const {
		return (Num == MaxSize - 1);
	};

	friend std::istream& operator>>(std::istream& in, TStack& s) {
		int count;
		std::cout << "Enter the number of elements to push (max " << s.MaxSize << "): ";
		in >> count;

		if (count > s.MaxSize) {
			std::cerr << "Too many elements! Only " << s.MaxSize << " allowed." << std::endl;
			return in;
		}

		std::cout << "Enter " << count << " elements: ";
		for (int i = 0; i < count; ++i) {
			T value;
			in >> value;
			if (s.Full()) {
				std::cerr << "Stack overflow. Stopping input." << std::endl;
				break;
			}
			s.Push(value);
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const TStack& s)
	{
		for (int i = 0; i <= s.Num; i++) {
			out << s.pMem[i] << " ";
		}
		return out;
	}
	
};


template <class T>
TStack <T>::TStack(int _MaxSize)		
{
	if (_MaxSize<0 || _MaxSize>MAX_SZ)
	{
		throw "Недопустимый размер стека";
	}
	MaxSize = _MaxSize;
	Num = -1;
	pMem = new T[MaxSize];
}



template <class T>
TStack<T>::TStack(const TStack& s)		
{
	if (s.MaxSize<0 || s.MaxSize>MAX_SZ || s.Num < -1 || s.Num >= s.MaxSize)
	{
		throw "Недопустимый размер стека";
	}
	MaxSize = s.MaxSize;
	Num = s.Num;
	pMem = new T[MaxSize];
	for (int i = 0; i <= Num; i++)
	{
		pMem[i] = s.pMem[i];
	}
}


template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& s) 
{
	if (this != &s)
	{
		if (MaxSize != s.MaxSize)
		{
			delete[] pMem;
			MaxSize = s.MaxSize;
			pMem = new T[MaxSize];
		}
		Num = s.Num;
		for (int i = 0; i <= Num; i++)
		{
			pMem[i] = s.pMem[i];
		}
	}
	return *this;
}


template <class T>
bool TStack<T>::operator==(const TStack& s) const
{
	
	if (this == &s)
	{
		return true;
	}
	if (MaxSize != s.MaxSize)
	{
		return false;
	}
	if (Num != s.Num)
	{
		return false;
	}
	for (int i = 0; i <= Num; i++)
	{
		if (pMem[i] != s.pMem[i])
		{
			return false;
		}
	}
	return true;
}


template <class T>
bool TStack<T>::operator!=(const TStack& s) const 
{

	return !(*this == s);
}


template <class T>
T TStack<T>::Pop()
{
	if (Empty())
	{
		throw - 2;
	}
	T tmp = pMem[Num];
	Num--;
	return tmp;
}



template <class T>
void TStack<T>::Push(T val)
{
	if (Full())
	{
		throw - 2;
	}
	Num++;
	pMem[Num] = val;
}


template <class T>
bool TStack<T>::Check(std::string str)
{
	TStack <char> s;
	bool res = true;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.Push('(');
		}
		if (str[i] == ')')
		{
			if (s.Empty())
			{
				return false;

			}
			s.Pop();
		}
	}
	return true;
}


template <class T>
T TStack<T>::Top() const
{
	if (Empty())
	{
		throw "пустой стек";
	}
	return pMem[Num];
}*/
template <class T>
struct Node {
	T element;
	Node* nextElement;
};

template <class T>
class TStack {
private:
	Node<T>* top;
	size_t maxSize;
	size_t currentSize;

public:
	TStack(size_t size = MAX_SZ);
	~TStack();
	TStack(const TStack& s);
	TStack& operator=(const TStack<T>& s);
	bool operator==(const TStack& s) const;
	bool operator!=(const TStack& s) const;
	void Push(T val);
	T Pop();
	bool isEmpty() const;
	bool isFull() const;
	T getTop() const;
	void Clear();
	bool Check(const std::string& str);

	friend std::istream& operator>>(std::istream& in, TStack& s) {
		T value;
		in >> value;
		s.Push(value);
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const TStack& s) {
		if (s.isEmpty())
			throw - 1;
		Node<T>* current = s.top;
		while (current != nullptr) {
			out << current->element << " ";
			current = current->nextElement;
		}
		return out;
	}
};

template <class T>
TStack<T>::TStack(size_t size) : maxSize(size), currentSize(0), top(nullptr) {
	if (size <= 0) {
		throw - 1;
	}
	if (size > MAX_SZ) {
		throw - 1;
	}
}

template <class T>
TStack<T>::~TStack() {
	Clear();
}

template <class T>
TStack<T>::TStack(const TStack<T>& s) : maxSize(s.maxSize), currentSize(s.currentSize), top(nullptr) {
	if (s.top == nullptr) {
		top = nullptr;
	}
	else {
		Node<T>* current = s.top;
		Node<T>* last = nullptr;
		while (current != nullptr) {
			Node<T>* newNode = new Node<T>;
			newNode->element = current->element;
			newNode->nextElement = nullptr;

			if (last == nullptr) {
				top = newNode;
			}
			else {
				last->nextElement = newNode;
			}

			last = newNode;
			current = current->nextElement;
		}
	}
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& s) {
	if (this == &s)
		return *this;

	Clear();

	maxSize = s.maxSize;
	currentSize = s.currentSize;

	if (s.top == nullptr) {
		top = nullptr;
	}
	else {
		Node<T>* current = s.top;
		Node<T>* last = nullptr;
		while (current != nullptr) {
			Node<T>* newNode = new Node<T>;
			newNode->element = current->element;
			newNode->nextElement = nullptr;

			if (last == nullptr) {
				top = newNode;
			}
			else {
				last->nextElement = newNode;
			}

			last = newNode;
			current = current->nextElement;
		}
	}

	return *this;
}

template <class T>
bool TStack<T>::operator==(const TStack<T>& s) const {


	if (currentSize != s.currentSize) {
		return false;
		Node<T>* tmp1 = top;
		Node<T>* tmp2 = s.top;
		while ((tmp1 != nullptr) && (tmp2 != nullptr)) {
			if ((tmp1->element) != (tmp2->element)) return false;
			tmp1 = tmp1->nextElement;
			tmp2 = tmp2->nextElement;
		}
		if (tmp1 == tmp2) return true;
		return false;
	}
}

template <class T>
bool TStack<T>::operator!=(const TStack<T>& s) const {
	return !(*this == s);
}

template <class T>
void TStack<T>::Push(T val) {
	if (isFull()) {
		throw - 1;
	}
	Node<T>* newNode = new Node<T>;
	newNode->element = val;
	newNode->nextElement = top;
	top = newNode;
	currentSize++;
}

template <class T>
T TStack<T>::Pop() {
	if (isEmpty())
		throw - 1;

	Node<T>* temp = top;
	T value = top->element;
	top = top->nextElement;
	delete temp;
	currentSize--;
	return value;
}

template <class T>
bool TStack<T>::isEmpty() const {
	return top == nullptr;
}

template <class T>
bool TStack<T>::isFull() const {
	//return currentSize >= maxSize;
	try {
		Node<T>* temp = new Node<T>;
		delete temp;
		return false;
	}
	catch (const std::bad_alloc&) {
		return true;
	}
}

template <class T>
T TStack<T>::getTop() const {
	if (isEmpty())
		throw - 1;
	return top->element;
}

template <class T>
void TStack<T>::Clear() {
	while (!isEmpty()) {
		Pop();
	}
}

template <class T>
bool TStack<T>::Check(const std::string& str) {
	TStack<char> s;
	for (char ch : str) {
		if (ch == '(') {
			s.Push('(');
		}
		else if (ch == ')') {
			if (s.isEmpty()) {
				return false;
			}
			s.Pop();
		}
	}
	return s.isEmpty();
}


//--------------------------------------------------------------------------------


class TCalc
{
	std::string infix, postfix;
	TStack <double> StNum;
	TStack <char> StChar;

public:
	void ToPostfix();			
	double CalcPostfix();		
	double Calc();				
	double PerformOperation(double firstNum, double secondNum, char op);	
	double stringToDouble(const std::string& str);
	int GetPriority(char op);	

	void SetInfix(const std::string& stroka)
	{
		infix = stroka;
	}
	std::string GetPostfix() const
	{
		return postfix;
	}
	std::string GetInfix() const
	{
		return infix;
	}
};



int TCalc::GetPriority(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	if (op == '^')
	{
		return 3;
	}
	return 0;
}

double TCalc::stringToDouble(const std::string& str)
{
	double result = 0.0;
	bool negative = false;
	size_t i = 0;

	if (i < str.size() && str[i] == '-') {
		negative = true;
		i++;
	}
	else if (i < str.size() && str[i] == '+') {
		i++;
	}

	while (i < str.size() && isdigit(str[i])) {
		result = result * 10 + (str[i] - '0');
		i++;
	}

	if (i < str.size() && str[i] == '.') {
		i++;
		double fraction = 1.0;
		while (i < str.size() && isdigit(str[i])) {
			fraction /= 10;
			result += (str[i] - '0') * fraction;
			i++;
		}
	}

	if (i < str.size()) {
		throw std::invalid_argument("Invalid input string");
	}
	return negative ? -result : result;
}

double TCalc::CalcPostfix()
{
	StNum.Clear();
	std::string number = "";

	for (int i = 0; i < postfix.size(); i++)
	{
		char sim = postfix[i];

		if (isdigit(sim) || sim == '.')
		{
			number += sim;		
		}
		else if (sim == ' ' && !number.empty())
		{
			double num = stringToDouble(number);
			StNum.Push(num);
			number = "";
		}
		else if (sim == '+' || sim == '-' || sim == '*' || sim == '/' || sim == '^' || sim == '~')
		{
			if (StNum.isEmpty())
			{
				throw - 1;
			}
			double secondNum = StNum.Pop();
			double firstNum = StNum.Pop();
			double result = PerformOperation(firstNum, secondNum, postfix[i]);
			StNum.Push(result);
		}
	}

	if (!number.empty()) {
		double val = stringToDouble(number);
		StNum.Push(val);
	}
	if (StNum.isEmpty())
	{
		throw "ошибка";
	}
	double result = StNum.Pop();
	return result;

}



void TCalc::ToPostfix()
{
	postfix = "";
	StChar.Clear();
	int b = 0;
	std::string number = "";

	for (int i = 0; i < infix.size(); i++)
	{
		char sim = infix[i];
		if (isdigit(sim) || sim == '.')
		{
			number += sim;  
			if (i == infix.size() - 1 || (!isdigit(infix[i + 1]) && infix[i + 1] != '.'))		
			{
				postfix += number + " ";
				number = "";
			}
		}
		else if (sim == '(')
		{
			StChar.Push(sim);
			b++;
		}
		else if (sim == ')')
		{
			while (!StChar.isEmpty() && StChar.getTop() != '(')
			{
				postfix += StChar.Pop();
				postfix += " ";
			}
			StChar.Pop();
			b--;
			if (b < 0) {
				throw std::invalid_argument("not match");
			}
		}
		else if (sim == '+' || sim == '-' || sim == '*' || sim == '/' || sim == '^')
		{
			while (!StChar.isEmpty() && GetPriority(StChar.getTop()) >= GetPriority(sim))
			{
				postfix += StChar.Pop();
				postfix += " ";
			}
			StChar.Push(sim);
		}
	}
	while (!StChar.isEmpty())		
	{
		postfix += StChar.Pop();
		postfix += " ";
	}
}


double TCalc::Calc()
{
	bool expectOperand = true; 
	int b = 0;
	for (size_t i = 0; i < infix.length(); ++i) {
		char token = infix[i];

		
		if (token == ' ') {
			continue;
		}

		
		if (isdigit(token) || token == '.') {
			std::string number;
			while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
				number += infix[i++];
			}
			--i; 
			StNum.Push(stringToDouble(number));
			expectOperand = false; 
		}
		
		else if (token == '(') {
			StChar.Push(token);
			expectOperand = true; 
			b++;
		}
		
		else if (token == ')') {
			b--;
			
			while (!StChar.isEmpty() && StChar.getTop() != '(') {
				char op = StChar.Pop();
				double secondNum = StNum.Pop();
				double firstNum = StNum.Pop();
				StNum.Push(PerformOperation(firstNum, secondNum, op));
			}
			if (!StChar.isEmpty() && StChar.getTop() == '(') {
				StChar.Pop(); 
			}
			expectOperand = false;
		}
		
		else {
			
			if (token == '-' && expectOperand) {
				std::string number = "-";
				++i;
				while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
					number += infix[i++];
				}
				--i; 
				StNum.Push(stringToDouble(number));
				expectOperand = false; 
				continue;
			}

			
			while (!StChar.isEmpty() && GetPriority(StChar.getTop()) >= GetPriority(token)) {
				char op = StChar.Pop();
				double secondNum = StNum.Pop();
				double firstNum = StNum.Pop();
				StNum.Push(PerformOperation(firstNum, secondNum, op));
			}
			StChar.Push(token);
			expectOperand = true; 
		}
	}

	
	while (!StChar.isEmpty()) {
		char op = StChar.Pop();
		double secondNum = StNum.Pop();
		double firstNum = StNum.Pop();
		StNum.Push(PerformOperation(firstNum, secondNum, op));
	}
	if (b != 0) {
		throw std::invalid_argument("not match");
	}
	return StNum.Pop();
}



double TCalc::PerformOperation(double firstNum, double secondNum, char op) {
	switch (op) {
	case '+': return firstNum + secondNum;
	case '-': return firstNum - secondNum;
	case '*': return firstNum * secondNum;
	case '/':
		if (secondNum == 0)
			throw std::runtime_error("Division by zero");
		return firstNum / secondNum;
	case '^': return pow(firstNum, secondNum);
	default: throw std::invalid_argument("Invalid operator");
	}
}

