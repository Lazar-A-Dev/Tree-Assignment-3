#pragma once
#include<iostream>
using namespace std;
class Node {
public:
	int info;
	Node* left, * right, * parent;

	Node() {
		info = 0;
		left = right = parent = NULL;
	}

	Node(int i) {
		info = i;
		left = right = parent = NULL;
	}

	~Node() {}

	bool IsEqual(int p) {
		return (p == info);
	}

	void Print() {
		cout << "[" << info << "]" << " ";
	}

	int ReturnInfo() {
		return info;
	}

	bool Compare(Node* p) {
		if (this->info == p->info)
			return true;
		return false;
	}

	bool operator == (Node* tmp) {
		if (this->info == tmp->info)
			return true;
		return false;
	}
};
