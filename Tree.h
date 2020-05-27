#include <iostream>



template <typename T>
class Tree {

private:
	//��������� �����
	int num = 0; //���-�� �������� ������
	struct Branch
	{
		T data; //������
		Branch* son; //��������� �� �������� �������
		Branch* brother;
	};
	Branch* root = 0; //������

	void mDelete(Branch* branch);
	void insert(T data, Branch*& branch);
	void print(Branch* branch);
	bool isEmpty(Branch*& branch);
	//Branch* deleteElement(Branch*& branch, T data);
	bool isContains(Branch*& branch, T data);
public:
	~Tree();
	bool isContains(T data) {
		return isContains(root, data);
	}
	Branch* getRoot() {
		return root;
	}
	void clear();
	void insert(T data);
	void print() {
		print(root);
	}
	bool isEmpty() {
		return isEmpty(root);
	}
	//Branch* deleteElement(T data) {
	//	return deleleElement(root, data);
	//}
};
template <typename T>
Tree<T>::~Tree() {
	clear();
}
template <typename T>
bool Tree<T>::isContains(Branch*& branch, T data) {
	if (branch == 0) return false;
	if (branch->data == data) return true;
	isContains(branch->son, data);
	isContains(branch->brother, data);
}


template <typename T>
void Tree<T>::insert(T data) {
	insert(data, root);
}

template <typename T>
void Tree<T>::clear() {
	mDelete(root);
	root = 0;
}

template <typename T>
void Tree<T>::insert(T data, Branch*& branch)
{
	//���� ����� �� ����������
	if (branch == 0)
	{ //�������� �� � ������� � ��� ������
		branch = new Branch;
		branch->data = data;
		branch->son = 0;
		branch->brother= 0;
		return;
	}
	else //����� ������ ��������
		if (branch->data > data)
		{ //���� ��� ������ ����, ��� � ���� ����� ��������� � ����
			insert(data, branch->son);
		}
		else
		{ //����� � �����
			insert(data, branch->brother);
		};
}

template <typename T>
void Tree<T>::print(Branch* branch)
{
	//���� ����� �� ����������, �� ������� �� ������
	if (branch == 0)return;
	std::cout << branch->data; //������ ���� �����
	//���������� ������� ������ ��������� �����
	if (branch->brother) {
		std::cout  << "->br";
		print(branch->brother);	
	}
	if (branch->son) {
		std::cout << "\n[" << branch->data << "]" << "->son"; 
		print(branch->son);
	}
	return;
}

template <typename T>
bool Tree<T>::isEmpty(Branch*& branch)
{
	if (branch == 0)
		return true;
	return false;
}

template <typename T>
void Tree<T>::mDelete(Branch* branch)
{
	if (branch == 0) return;
	mDelete(branch->son);
	mDelete(branch->brother);
	delete branch;
	return;
}