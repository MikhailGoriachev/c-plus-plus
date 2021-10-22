#pragma once
class Queue
{
public:
	static const int QUEUE_SIZE = 12;

private:	
	int back_;              // хвост очереди
	int data_[QUEUE_SIZE];  // данные очереди

public:
	Queue():back_() {  }

	Queue(int *data, int n):back_()
	{
		enqueueAll(data, n);
	}

	Queue(const Queue& queue) = default;

	~Queue() = default;
	Queue& operator=(const Queue &queue) =default;
	
	void enqueue(int value);
	void enqueueAll(int* values, int n);
	int  dequeue();
	int  front();
	int  back();
	void clear();

	// проверка очереди на опустошение (true, если стек пуст)
	bool isEmpty() const { return back_ == 0; }

	// проверка очереди на переполнение (true, если стек полон)
	bool isFull() const { return back_ == QUEUE_SIZE; }

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const Queue& queue);
};

