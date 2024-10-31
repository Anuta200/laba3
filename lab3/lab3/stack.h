#pragma once
#pragma once
template<class T>
class TStack
{
	T* pMem;
	int MaxSize, Num;
public:
	TStack(int _MaxSize = 10);
	TStack& operator=(const TStack& s);
	bool IsEmpty()
};