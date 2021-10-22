#pragma once
#include "pch.h"


// бинарное дерево
template <typename T>
class BinaryTree
{
public:

	// узел/лист дерева
	template <typename T>
	class NodeTree
	{
		// данные 
		T data_;

		// указатель на левую ветвь
		NodeTree* left_;
		
		// указатель на правую ветвь
		NodeTree* right_;

	public:

		// конструктор по умолчанию
		NodeTree() = default;

		// конструктор инициализирущий
		NodeTree(T data) : data_(data) {}

		// конструктор копирующий
		NodeTree(const NodeTree& nodeTree) = default;

		// деструктор 
		~NodeTree() = default;

		// перегрузка операции присваивания
		NodeTree<T>& operator=(const NodeTree& nodeTree) = default;

		// сеттер data_ 
		void setData(T data) { data_ = data; }

		// геттер data_ 
		T getData() { return data_; }

		// сеттер left_
		void setLeft(NodeTree* left) { left_ = left; }

		// геттер left_ 
		NodeTree* getLeft() { return left_; }

		// сеттер right_ 
		void setRight(NodeTree* right) { right_ = right; }

		// геттер right_ 
		NodeTree* getRight() { return right_; }

		// перегрузка операции вывода 
		friend ostream& operator<<(ostream& os, NodeTree& node)
		{
			os << node.data_;
		}
	};

private:

	// указатель на корень 
	NodeTree<T>* root_;

	// счётчик узлов/листов в дереве
	int counter_;

public:
	
#pragma region Конструкторы, деструкторы, перегрузка операции присваивания

	// конструктор по умолчанию
	BinaryTree(): root_(), counter_() { }

	// конструктор инициализирующий
	BinaryTree(T* arr, int n)
	{
		addAll(arr, n);
	}

	// конструктор копирующий
	BinaryTree(BinaryTree& bineryTree) = default;

	// TODO: !!! временное неправильное решение !!! 
	~BinaryTree() = default;

#pragma endregion

#pragma region Методы

	// добавление элемента
	void add(T value)
	{
		// создание нового узла
		NodeTree<T>* newNode = new NodeTree<T>(value);

		// добавление в пустое дерево
		if (root_ == nullptr)
		{
			// установка root_ на новый узел
			root_ = newNode;

			// увеличение счётчика узлов
			counter_++;

			return;
		}


		// добавление в непустое дерево

		// текущий узел
		NodeTree<T>* node = root_;

		// поиск места для доабвления
		while (true)
		{
			// текущее значение элемента
			T valueNode = node->getData();

			// если value больше значения текущего узла 
			if (value > valueNode)
			{
				// если есть пустое место
				if (node->getRight() == nullptr)
				{
					// устанавливаем newNode
					node->setRight(newNode);

					break;
				}

				// переход на следующий узел
				node = node->getRight();
			} // if (value > valueNode)

			// если value меньше значения текущего узла 
			if (value < valueNode)
			{
				// если есть пустое место
				if (node->getLeft() == nullptr)
				{
					// устанавливаем newNode
					node->setLeft(newNode);

					break;
				}

				// переход на следующий узел
				node = node->getLeft();
			} // if (value < valueNode)

		} // while (true)

		// увеличение счётчика
		counter_++;
	} // void add


	// добавление массива элементов
	void addAll(T* arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			add(arr[i]);
		}
	} // void addAll


	// поиск элемента
	NodeTree<T>* find(T key)
	{
		// если дерево пустое
		if (isEmpty())
			return nullptr;
		
		// текущий элемент
		NodeTree<T>* node = root_;

		// поиск в дереве
		while (node != nullptr)
		{
			// значение текущего элемента
			T tmp = node->getData();

			// если значени текущего элемента равно ключу
			if (tmp == key)
				return node;

			// если значение меньше ключа 
			node = key < tmp ? node->getLeft() : node->getRight();
		}

		// если значение не найдено
		return node;

	} // Node* find


	// опустошение бинарного дерева
	bool isEmpty() { return root_ == nullptr; }

	
	// счётчик
	int counter() { return counter_; }


	NodeTree<T>* getRoot() { return root_; }

#pragma endregion

private:

	// обход узлов дерева для вывода
	static ostream& show(ostream& os, NodeTree<T>* node)
	{
		// если текущий узел является nullptr
		if (node == nullptr) return os;

		// прохождение по левому поддереву
		show(os, node->getLeft());

		// вывод текущего значения
		os << node->getData();

		// прохождение по правому поддереву
		show(os, node->getRight());

		return os;
	}

	// обход узлов дерева для записи в бинарный файл
	void writeBin(FILE* file, NodeTree<T>* node)
	{
		// если текущий узел является nullptr
		if (node == nullptr) return;

		// прохождение по левому поддереву
		writeBin(file, node->getLeft());

		// запись в файл текущего значения
		node->getData().write(file);

		// прохождение по правому поддереву
		writeBin(file, node->getRight());

	}



public:

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, BinaryTree<T>& binaryTree)
	{
		// если дерево пустое
		if (binaryTree.root_ == nullptr)
			os << " Binary Tree: бинарное дерево опустошено!";

		else
			// вывод бинарного дерева
			show(os, binaryTree.root_);

		return os;
	}

	// запись в бинарный файл
	void write(FILE* file)
	{
		// если дерево пустое
		if (root_ == nullptr)
			return;

		else
			// вывод бинарного дерева
			writeBin(file, root_);

	}		

	// чтение из бинарного файла
	void read(FILE* file)
	{
		T tmp;

		while (true)
		{
			// чтение текущего значения
			tmp.read(file);

			if (feof(file)) break;

			// запись текущего объекта в дерево
			add(tmp);
		}
	}
};

