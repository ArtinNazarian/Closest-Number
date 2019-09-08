// ClosestNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"ClosestNumber.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int userInput, closestValue;
	int numArray[] = { 36,21,55,14,3,95,100,46,77,79,83,11,16,33,90 };
	int size = sizeof(numArray) / sizeof(numArray[0]);

	BST myTree;

	for (int i = 0; i < size; i++)
	{
		myTree.Insert(numArray[i]);
	}

	cout << "Here is the list of numbers in the tree\n";
	myTree.print();
	

	cout << "Enter a number from 1 to 100 and I will find its closest number: ";
	cin >> userInput;
	closestValue=myTree.closestNode(userInput);
	cout << "Closest number to " << userInput << " is " << closestValue;

	

}

