#pragma once
class Queue
{
public:
	static const int QUEUE_SIZE = 12;

private:	
	int back_;              // ����� �������
	int data_[QUEUE_SIZE];  // ������ �������

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

	// �������� ������� �� ����������� (true, ���� ���� ����)
	bool isEmpty() const { return back_ == 0; }

	// �������� ������� �� ������������ (true, ���� ���� �����)
	bool isFull() const { return back_ == QUEUE_SIZE; }

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const Queue& queue);
};

