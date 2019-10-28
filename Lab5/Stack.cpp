#include "Stack.h"

Stack::Stack() {top_index = -1;}

bool Stack::empty() const
{
	return (top_index == -1);
}

int Stack::top() const
{
	if (!empty())
		return data[top_index];
}

void Stack::push(int x)
{
	if (top_index != size)
		data[++top_index] = x;
}

int Stack::pop()
{
	if (!empty())
		--top_index;
		return top();
}

