#pragma once
#include<iostream>
using namespace std;
#include"Node.h"
class TreeBS
{
public:
	Node* root;
	int nodeNumber;
	
	TreeBS();
	~TreeBS();
	void DeleteTree(Node* p);

	Node* FindNode(int p);

	void InsertOrganised(int p);
	void InsertNO(int p);
	void InsertMax(int p);
	void InsertMin(int p);

	void PreorderPrint();
	void PreorderPrint(Node* p);
	void PostorderPrint();
	void PostorderPrint(Node* p);
	void InorderPrint();
	void InorderPrint(Node* p);

	int Height();
	int Height(Node* p);
	int Max(int a, int b);
	int NumberOfLeaves();
	int NumberOfLeaves(Node* p);
	void DeleteLeaves();
	void DeleteLeaves(Node* p);
	void Mirror();
	void Mirror(Node* p);

	void DeleteNode(int p);
	int ReturnNodeNumber() { return nodeNumber; }
	void NodeSwitch(int a, int b);
	void SwitchRest(Node* a, Node* b);
};

