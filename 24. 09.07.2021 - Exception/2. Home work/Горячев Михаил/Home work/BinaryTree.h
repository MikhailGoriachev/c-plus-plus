#pragma once
#include "pch.h"


// �������� ������
template <typename T>
class BinaryTree
{
public:

	// ����/���� ������
	template <typename T>
	class NodeTree
	{
		// ������ 
		T data_;

		// ��������� �� ����� �����
		NodeTree* left_;
		
		// ��������� �� ������ �����
		NodeTree* right_;

	public:

		// ����������� �� ���������
		NodeTree() = default;

		// ����������� ���������������
		NodeTree(T data) : data_(data) {}

		// ����������� ����������
		NodeTree(const NodeTree& nodeTree) = default;

		// ���������� 
		~NodeTree() = default;

		// ���������� �������� ������������
		NodeTree<T>& operator=(const NodeTree& nodeTree) = default;

		// ������ data_ 
		void setData(T data) { data_ = data; }

		// ������ data_ 
		T getData() { return data_; }

		// ������ left_
		void setLeft(NodeTree* left) { left_ = left; }

		// ������ left_ 
		NodeTree* getLeft() { return left_; }

		// ������ right_ 
		void setRight(NodeTree* right) { right_ = right; }

		// ������ right_ 
		NodeTree* getRight() { return right_; }

		// ���������� �������� ������ 
		friend ostream& operator<<(ostream& os, NodeTree& node)
		{
			os << node.data_;
		}
	};

private:

	// ��������� �� ������ 
	NodeTree<T>* root_;

	// ������� �����/������ � ������
	int counter_;

public:
	
#pragma region ������������, �����������, ���������� �������� ������������

	// ����������� �� ���������
	BinaryTree(): root_(), counter_() { }

	// ����������� ����������������
	BinaryTree(T* arr, int n)
	{
		addAll(arr, n);
	}

	// ����������� ����������
	BinaryTree(BinaryTree& bineryTree) = default;

	// TODO: !!! ��������� ������������ ������� !!! 
	~BinaryTree() = default;

#pragma endregion

#pragma region ������

	// ���������� ��������
	void add(T value)
	{
		// �������� ������ ����
		NodeTree<T>* newNode = new NodeTree<T>(value);

		// ���������� � ������ ������
		if (root_ == nullptr)
		{
			// ��������� root_ �� ����� ����
			root_ = newNode;

			// ���������� �������� �����
			counter_++;

			return;
		}


		// ���������� � �������� ������

		// ������� ����
		NodeTree<T>* node = root_;

		// ����� ����� ��� ����������
		while (true)
		{
			// ������� �������� ��������
			T valueNode = node->getData();

			// ���� value ������ �������� �������� ���� 
			if (value > valueNode)
			{
				// ���� ���� ������ �����
				if (node->getRight() == nullptr)
				{
					// ������������� newNode
					node->setRight(newNode);

					break;
				}

				// ������� �� ��������� ����
				node = node->getRight();
			} // if (value > valueNode)

			// ���� value ������ �������� �������� ���� 
			if (value < valueNode)
			{
				// ���� ���� ������ �����
				if (node->getLeft() == nullptr)
				{
					// ������������� newNode
					node->setLeft(newNode);

					break;
				}

				// ������� �� ��������� ����
				node = node->getLeft();
			} // if (value < valueNode)

		} // while (true)

		// ���������� ��������
		counter_++;
	} // void add


	// ���������� ������� ���������
	void addAll(T* arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			add(arr[i]);
		}
	} // void addAll


	// ����� ��������
	NodeTree<T>* find(T key)
	{
		// ���� ������ ������
		if (isEmpty())
			return nullptr;
		
		// ������� �������
		NodeTree<T>* node = root_;

		// ����� � ������
		while (node != nullptr)
		{
			// �������� �������� ��������
			T tmp = node->getData();

			// ���� ������� �������� �������� ����� �����
			if (tmp == key)
				return node;

			// ���� �������� ������ ����� 
			node = key < tmp ? node->getLeft() : node->getRight();
		}

		// ���� �������� �� �������
		return node;

	} // Node* find


	// ����������� ��������� ������
	bool isEmpty() { return root_ == nullptr; }

	
	// �������
	int counter() { return counter_; }


	NodeTree<T>* getRoot() { return root_; }

#pragma endregion

private:

	// ����� ����� ������ ��� ������
	static ostream& show(ostream& os, NodeTree<T>* node)
	{
		// ���� ������� ���� �������� nullptr
		if (node == nullptr) return os;

		// ����������� �� ������ ���������
		show(os, node->getLeft());

		// ����� �������� ��������
		os << node->getData();

		// ����������� �� ������� ���������
		show(os, node->getRight());

		return os;
	}

	// ����� ����� ������ ��� ������ � �������� ����
	void writeBin(FILE* file, NodeTree<T>* node)
	{
		// ���� ������� ���� �������� nullptr
		if (node == nullptr) return;

		// ����������� �� ������ ���������
		writeBin(file, node->getLeft());

		// ������ � ���� �������� ��������
		node->getData().write(file);

		// ����������� �� ������� ���������
		writeBin(file, node->getRight());

	}



public:

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, BinaryTree<T>& binaryTree)
	{
		// ���� ������ ������
		if (binaryTree.root_ == nullptr)
			os << " Binary Tree: �������� ������ ����������!";

		else
			// ����� ��������� ������
			show(os, binaryTree.root_);

		return os;
	}

	// ������ � �������� ����
	void write(FILE* file)
	{
		// ���� ������ ������
		if (root_ == nullptr)
			return;

		else
			// ����� ��������� ������
			writeBin(file, root_);

	}		

	// ������ �� ��������� �����
	void read(FILE* file)
	{
		T tmp;

		while (true)
		{
			// ������ �������� ��������
			tmp.read(file);

			if (feof(file)) break;

			// ������ �������� ������� � ������
			add(tmp);
		}
	}
};

