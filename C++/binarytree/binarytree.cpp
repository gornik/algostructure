#include <binarytree.h>

template <class T>
BinaryTree<T>::BinaryTree()
	: root(nullptr), levels(0) {}

template <class T>
BinaryTree<T>::~BinaryTree() {
	delete root;
}

template <class T>
unsigned int BinaryTree<T>::Levels() const {
	return levels;
}

template <class T>
void BinaryTree<T>::Add(T i) {

	levels++;

	if (root == nullptr) {
		root = NewNode<T>(i);
		return;
	}

	if (root->Value < i) {
		return add(i, root->Right);
	}
	add(i, root->Left);
	return;
}

template <class T>
void BinaryTree<T>::add(T i, Tree<T>* &leaf) {
	if (leaf == nullptr) {
		leaf = NewNode<T>(i);
		return;
	}
	if (leaf->Value < i) {
		return add(i, leaf->Right);
	}
	return add(i, leaf->Left);
}

template <class T>
vector<T> BinaryTree<T>::Walk() {

	vector<T> out;
	if (root == nullptr) {
		cout << "here\n";
		return out;
	}

	walk(root->Left, out);
	out.push_back(root->Value);
	walk(root->Right, out);

	return out;
}

template <class T>
vector<T> BinaryTree<T>::walk(Tree<T> *leaf, vector<T>& out) {
	if (leaf == nullptr) {
		return out;
	}

	walk(leaf->Left, out);
	out.push_back(leaf->Value);
	walk(leaf->Right, out);

	return out;
}

int main() {
	BinaryTree<int> btree;
	vector<int> tree;

	btree.Add(0);
	btree.Add(4);
	btree.Add(5);
	btree.Add(-2);
	btree.Add(-1);
	btree.Add(8);

	tree = btree.Walk();

	cout << "[ ";
	for (auto x = tree.begin(); x != tree.end(); ++x) {
		cout << (*x) << " ";
	}
	cout << "]\n";

	BinaryTree<string> btreestr;
	vector<string> treestr;

	btreestr.Add("YoYo");
	btreestr.Add("Hi");
	btreestr.Add("Howdy");
	btreestr.Add("Sup");
	btreestr.Add("Hello");
	btreestr.Add("Wassup");

	treestr = btreestr.Walk();

	cout << "[ ";
	for (auto x = treestr.begin(); x != treestr.end(); ++x) {
		cout << (*x) << " ";
	}
	cout << "]\n";


	BinaryTree<double> btreedbl;
	vector<double> treedbl;
	btreedbl.Add(0.001);
	btreedbl.Add(-0.001);
	btreedbl.Add(0.0123);
	btreedbl.Add(123123.00);
	btreedbl.Add(123121.001);
	btreedbl.Add(0.021);

	treedbl = btreedbl.Walk();

	cout << "[ ";
	for (auto x = treedbl.begin(); x != treedbl.end(); ++x) {
		cout << (*x) << " ";
	}
	cout << "]\n";

	{ BinaryTree<int> nbtree; }

	return 0;
}