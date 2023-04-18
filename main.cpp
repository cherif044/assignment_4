// ConsoleApplication83.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>
#include "linkedlist.h"
void insertAfter(vector<int>& x, int first, int second)
{
	vector<int>::iterator y;
	for (y = x.begin(); y != x.end(); y++)
	{
		if (*y == first)
		{
			x.insert(y+1, second);                               //looping over the vector and inserting in the next position in case the values are equal
			y++;                                                 // incrementing the itirator because we don't need to check the added value
		}
	}
}
int main()
{
	vector<int> x;
	int input, first, second;
	for (int i = 0; i < 7; i++)
	{
		cout << "enter number of index " << i + 1 << " :" << endl;
		cin >> input;                                                                    //filling vector with input
		x.push_back(input);
	}
	cout << endl;
	cout << "enter the number to be used in insertAfter as the first number: ";
	cin >> first;                                                                        // taking parameters of insertAfter function
	cout << "enter the number to be used in insertAfter as the second number: ";
	cin >> second;
	insertAfter(x, first, second);
	vector<int>::iterator it;
	cout << "vector after using insertAfter: " << endl;
	for (it = x.begin(); it != x.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "now we will copy the vector to a linked list using occurences: " << endl;
	linkedlist y;
	y.copy_vector(x);
	y.display();
	cout << endl;
	cout << "sum of list: " << y.sum();
	cout << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
