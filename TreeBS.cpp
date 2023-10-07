#include "TreeBS.h"

TreeBS::TreeBS() {
	root = NULL;
	nodeNumber = 0;
}

TreeBS::~TreeBS() {
	DeleteTree(root);
}

void TreeBS::DeleteTree(Node* p) {
	if (p != NULL) {
		DeleteTree(p->left);
		DeleteTree(p->right);
		delete p;
	}
}

Node* TreeBS::FindNode(int p) {
	Node* tmp = root;
	while (tmp != NULL && tmp->info != p) {
		if (tmp->info < p) {
			tmp = tmp->right;
		}
		else if (tmp->info > p) {
			tmp = tmp->left;
		}
	}
	return tmp;
}

void TreeBS::InsertOrganised(int p) {
	Node* next = root;
	Node* previous = NULL;

	while (next != NULL) {
		previous = next;

		if (next->info > p) {
			next = next->left;
		}
		else if (next->info < p) {
			next = next->right;
		}
		else return;
	}

	if (root == NULL) {
		root = new Node(p);
		nodeNumber = 1;
	}
	else if (previous->info > p) {
		previous->left = new Node(p);
		previous->left->parent = previous;
		nodeNumber++;
	}
	else if (previous->info < p) {
		previous->right = new Node(p);
		previous->right->parent = previous;
		nodeNumber++;
	}
}

void TreeBS::InsertNO(int p) {
	Node* tmp = root;
	Node* next = NULL;

	while (next != NULL) {
		
	}
}

void TreeBS::InsertMax(int p) {

}

void TreeBS::InsertMin(int p) {

}

void TreeBS::PreorderPrint() {
	cout << "Preorder stablo: ";
	PreorderPrint(root);
}

void TreeBS::PreorderPrint(Node* p) {
	if (p != NULL) {
		p->Print();
		PreorderPrint(p->left);
		PreorderPrint(p->right);
	}
}

void TreeBS::PostorderPrint() {
	cout << "Postorder stablo: ";
	PostorderPrint(root);
}

void TreeBS::PostorderPrint(Node* p) {
	if (p != NULL) {
		PreorderPrint(p->left);
		PreorderPrint(p->right);
		p->Print();
	}
}

void TreeBS::InorderPrint() {
	cout << "Inorder stablo: ";
	InorderPrint(root);
}

void TreeBS::InorderPrint(Node* p) {
	if (p != NULL) {
		PreorderPrint(p->left);
		p->Print();
		PreorderPrint(p->right);
	}
}

void TreeBS::DeleteNode(int p) {
	Node* tmp = FindNode(p);
	if (tmp == root) {
		DeleteTree(root);
	}
	else {
		if (tmp->left != NULL && tmp->right == NULL) {
			tmp->left->parent = tmp->parent;
			tmp->parent->left = tmp->left;
			delete tmp;
			tmp = NULL;
			nodeNumber--;
		}

		else if (tmp->left == NULL && tmp->right != NULL) {
			tmp->right->parent = tmp->parent;
			tmp->parent->right = tmp->right;
			delete tmp;
			tmp = NULL;
			nodeNumber--;
		}

		else if (tmp->left == NULL && tmp->right == NULL) {
			delete tmp;
			tmp = NULL;
			nodeNumber--;
		}

		else if (tmp->left != NULL && tmp->right != NULL) {
			throw "Nije moguce ukloniti ovaj cvor, posto sadrzi oba potomaka";
		}
	}
}
int TreeBS::Height(){
	return Height(root);
}

int TreeBS::Height(Node* p) {
	if (p == NULL)
		return 0;
	if (p->left == NULL && p->right == NULL)
		return 1;
	return 1 + Max(Height(p->left), Height(p->right));
}

int TreeBS::Max(int a, int b) {
	if (a >= b)
		return a;
	else return b;
}

int TreeBS::NumberOfLeaves() {
	return NumberOfLeaves(root);
}

int TreeBS::NumberOfLeaves(Node* p) {
	if (p == NULL)
	return 0;

	if (p->left == NULL && p->right == NULL)
		return 1;

	return NumberOfLeaves(p->left) + NumberOfLeaves(p->right);

}

void TreeBS::DeleteLeaves() {
	if (root->left == NULL && root->right == NULL)
		DeleteTree(root);

	DeleteLeaves(root);
}

void TreeBS::DeleteLeaves(Node* p) {
	if (p == NULL)
		return;
	if (p->left != NULL) {
		if (p->left->left == NULL && p->left->right == NULL) {
			delete p->left;
			p->left = NULL;
		}
	}

	if (p->right != NULL) {
		if (p->right->left == NULL && p->right->right == NULL) {
			delete p->right;
			p->right = NULL;
		}
	}
	DeleteLeaves(p->left);
	DeleteLeaves(p->right);
}

void TreeBS::NodeSwitch(int a, int b) {
	Node* na = FindNode(a);//cvor a
	Node* nb = FindNode(b);//cvor b

	if (na == NULL || nb == NULL)
		throw exception("Nije moguca zamena ako vrednost ne postoji");

	Node* naParent = na->parent;
	Node* nbParent = nb->parent;

	if (na->parent != NULL && nb->parent != NULL) {//Za cvorove koji imaju roditelje

		if (na->parent->left == na && nb->parent->left == nb) {// levi roditelj na, levi roditelj nb
			Node* tmp = nb->parent;
			nb->parent = na->parent;
			na->parent = tmp;

			tmp = nbParent->left;
			nbParent->left = naParent->left;
			naParent->left = tmp;

			SwitchRest(na, nb);

		}

		else if (na->parent->left == na && nb->parent->right == nb) {//levi roditelj na, desni roditelj nb 		
			Node* tmp = nb->parent;
			nb->parent = na->parent;
			na->parent = tmp;

			tmp = nbParent->right;
			nbParent->right = naParent->left;
			naParent->left = tmp;
			
			SwitchRest(na, nb);

		}

		else if (na->parent->right == na && nb->parent->left == nb) {//desni roditelj na, levi roditelj nb 		
			Node* tmp = nb->parent;
			nb->parent = na->parent;
			na->parent = tmp;

			tmp = nbParent->left;
			nbParent->left = naParent->right;
			naParent->right = tmp;

			SwitchRest(na, nb);

		}

		else if (na->parent->right == na && nb->parent->right == nb) {//desni roditelj na, desni roditelj nb 		
			Node* tmp = nb->parent;
			nb->parent = na->parent;
			na->parent = tmp;

			tmp = nbParent->right;
			nbParent->right = naParent->right;
			naParent->right = tmp;

			SwitchRest(na, nb);

		}

	}

	else if (na->parent == NULL && nb->parent != NULL) {
		if (nb->parent->left == nb) {
			Node* tmp = nb->parent;
			nb->parent = na->parent;
			na->parent = tmp;

			tmp = nbParent->right;
			nbParent->right = na;
			na = tmp;
			
			SwitchRest(na, nb);
		}

		else if (nb->parent->right == nb) {
		
		}
	}
	else if (na->parent != NULL && nb->parent == NULL) {

	}
	

}

void TreeBS::SwitchRest(Node* na, Node* nb) {
	Node* tmp = NULL;

	if (na->left != NULL && nb->left != NULL) {
		tmp = nb->left;
		nb->left = na->left;
		na->left = tmp;
	}

	else if (na->right != NULL && nb->right != NULL) {
		tmp = nb->right;
		nb->right = na->right;
		na->right = tmp;
	}

	else if (na->left != NULL && nb->right != NULL) {
		tmp = nb->right;
		nb->right = na->left;
		na->left = tmp;
	}

	else if (na->right != NULL && nb->left != NULL) {
		tmp = nb->left;
		nb->left = na->right;
		na->right = tmp;
	}

	else if (na->left != NULL && nb->left == NULL && nb->right == NULL) {
		tmp = NULL;
		nb->left = na->left;
		na->left = tmp;
	}

	else if (na->right != NULL && nb->left == NULL && nb->right == NULL) {
		tmp = NULL;
		nb->right = na->right;
		na->right = tmp;
	}

	else if (na->left == NULL && nb->right == NULL && nb->left != NULL) {
		tmp = NULL;
		na->left = nb->left;
		nb->left = tmp;
	}

	else if (na->left == NULL && na->right == NULL && nb->right != NULL) {
		tmp = NULL;
		na->right = nb->right;
		nb->right = tmp;
	}
	
}

void TreeBS::Mirror() {
	Mirror(root);
}

void TreeBS::Mirror(Node* p) {
	if (p == NULL)
		return;
	
	Node* pom = p->left;
	p->left = p->right;
	p->right = pom;
	Mirror(p->left);
	Mirror(p->right);
}