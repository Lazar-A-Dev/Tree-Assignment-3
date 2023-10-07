#include<iostream>
#include"TreeBS.h"
#include"Node.h"
using namespace std;
void main() {

	TreeBS t;
	t.InsertOrganised(5);
	t.InsertOrganised(4);
	t.InsertOrganised(2);
	t.InsertOrganised(11);
	t.InsertOrganised(6);
	t.InsertOrganised(7);
	t.InsertOrganised(8);
	t.InsertOrganised(9);

	t.PreorderPrint();
	cout << endl;
	//t.PostorderPrint();
	//cout << endl;
	//t.InorderPrint();
	//t.DeleteNode(7);
	t.NodeSwitch(5, 8);
	//t.Mirror();
	t.PreorderPrint();
	cout << endl;
	cout << "Broj covra u stablu: " << t.ReturnNodeNumber() << endl;
	cout << "Visina cvora: " << t.Height() << endl;
	cout << "Broj listova: " << t.NumberOfLeaves() << endl;

	system("pause");
}