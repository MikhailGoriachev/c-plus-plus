// #pragma once

// #include "Form.h"
// #include "Subscriber.h"
// // узел/лист дерева
// template <typename T>
// class NodeTree
// {
// 	// данные 
// 	T data_;
// 
// 	// указатель на левую ветвь
// 	NodeTree* left_;
// 
// 	// указатель на правую ветвь
// 	NodeTree* right_;
// 
// public:
// 
// 	// конструктор по умолчанию
// 	NodeTree() = default;
// 
// 	// конструктор инициализирущий
// 	NodeTree(T data) : data_(data) {}
// 
// 	// конструктор копирующий
// 	NodeTree(const NodeTree& node) = default;
// 
// 	// деструктор 
// 	~NodeTree() = default;
// 
// 	// перегрузка операции присваивания
// 	NodeTree<T>& operator=(const NodeTree& node) = default;
// 
// 	// сеттер data_ 
// 	void setData(T data) { data_ = data; }
// 
// 	// геттер data_ 
// 	T getData() { return data_; }
// 
// 	// сеттер left_
// 	void setLeft(NodeTree* left) { left_ = left; }
// 
// 	// геттер left_ 
// 	NodeTree* getLeft() { return left_; }
// 
// 	// сеттер right_ 
// 	void setRight(NodeTree* right) { right_ = right; }
// 
// 	// геттер right_ 
// 	NodeTree* getRight() { return right_; }
// 
// 	// перегрузка операции вывода 
// 	friend ostream& operator<<(ostream& os, NodeTree& node)
// 	{
// 		os << node.data_;
// 	}
// };
// 

