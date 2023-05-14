//Queue
#include <iostream>
using namespace std;

class Queue
{
private:
	int* queue;
	int size;
	int front;
	int rear;
	int maxQueueSize;

public:
	Queue(int maxQueueSize) : maxQueueSize(maxQueueSize), front(-1), rear(-1), size(0) //큐 객체를 생성할 때 호출되는 함수/큐가 비어있음을 의미하도록 변수 초기화
	{
		queue = new int[maxQueueSize]; //큐의 원소를 저장할 동적 배열 
	}

	bool Qempty() //큐가 비어있는지 확인할 함수
	{
		return size == 0;
	}

	bool Qfull() //큐가 차있는지 확인할 함수
	{
		if (size == maxQueueSize)
			return true;
		else
			return false;
	}

	int getSize() 
	{
		return size;
	}

	void addQueue(int value) //큐가 꽉 차있는지 확인 후 큐에 원소 추가 
	{
		if (Qfull() == true)
		{
			throw "큐가 모두 차있습니다"; //예외처리
			return;
		}

		rear = (rear + 1) % maxQueueSize;
		queue[rear] = value;
		
		if (Qempty())
		{
			front = rear;
		}
		size++;
	}

	void subQueue() //큐가 비어있는지 확인 후 원소 제거 
	{
		if (Qempty())
		{
			throw "큐가 모두 비어있습니다"; //예외처리
			return;
		}

		front = (front + 1) % maxQueueSize;
		size--;
		
		if (Qempty())
		{
			front = -1;
			rear = -1;
		}
	}

	int frontIndex() //큐가 비어있는지 확인 후 맨 앞 원소 반환
	{
		if (Qempty())
		{
			throw "큐가 모두 비어있습니다."; //예외처리
			return 0;
		}
		else
			return queue[front];
	}

	~Queue() //큐 객체 소멸 함수 
	{
		delete[] queue;
	}
};
