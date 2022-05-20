#include <iostream>
using namespace std;

struct Elem
{
	Elem* link;
	int info;
};

void insert(Elem*& L, int info)
{
	Elem* tmp = new Elem; // 1
	tmp->info = info; // 2
	if (L != nullptr)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link; // 3
		T->link = tmp; // 4
	}
	else
	{
		L = tmp; // 5
	}
	tmp->link = L; // 6

}

int remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link; // 1
	int value = L->info; // 2
	if (T != L)
	{
		Elem* tmp = L->link; // 3
		delete L; // 4
		L = tmp; // 5
		T->link = L; // 6
	}
	else
	{
		delete L; // 4
		L = nullptr; // 7
	}
	return value; // 8

}

int count(Elem* L)
{
	if (L == nullptr)
		return 0;
	Elem* first = L;
	int k = 1;
	while (L->link != first)
	{
		k++;
		L = L->link;
	}
	return k;
}

void print(Elem* L)
{
	if (L == nullptr)
		return;
	Elem* first = L;
	while (L->link != first)
	{
		cout << L->info << " ";

		L = L->link;
	}
	cout << L->info << endl;
}

void removes(Elem*& L, int info)
{
	if (L == nullptr)
		return;

	Elem* first = L;
	while (L->link != first)
	{
		if (L->info == info && L == first)
		{
			remove(L);
			first = L;
		}
		if (L->info == info) 
		{	
			remove(L);
		}
		else
			L = L->link;
	}
	if (L->info == info)
		remove(L);
	L = first;
}

int main()
{
	Elem* L = nullptr;
	for (size_t i = 0; i < 5; i++)
		insert(L, rand() % 11);

	print(L);
	int info;
	cout << "info: "; cin>>info;
	removes(L, info);
	print(L);

	int k = count(L);
	for (size_t i = 0; i < k; i++)
		remove(L);

	return 0;
}