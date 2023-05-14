//Queue
#include <iostream>
#include "params.h"
#include "Data_Struct.h"
using namespace std;


Queue::Queue() //큐 객체를 생성할 때 호출되는 함수/큐가 비어있음을 의미하도록 변수 초기화
{
	this->front = -1;
	this->rear = -1;
	this->size = 0;
	queue = new unsigned int[MAX_QUEUE_SIZE]; //큐의 원소를 저장할 동적 배열 
}

bool Queue::Qempty() //큐가 비어있는지 확인할 함수
{
	return size == 0;
}

bool Queue::Qfull() //큐가 차있는지 확인할 함수
{
	if (size == MAX_QUEUE_SIZE)
		return true;
	else
		return false;
}

unsigned int Queue::getSize() 
{
	return size;
}

void Queue::addQueue(int value) //큐가 꽉 차있는지 확인 후 큐에 원소 추가 
{
	if (Qfull() == true)
	{
		throw "큐가 모두 차있습니다"; //예외처리
		return;
	}

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = value;
	
	if (Qempty())
	{
		front = rear;
	}
	size++;
}

unsigned int Queue::deleteQueue() //큐가 비어있는지 확인 후 원소 제거 
{
	if (Qempty())
	{
		throw "큐가 모두 비어있습니다"; //예외처리
		return;
	}

	front = (front + 1) % MAX_QUEUE_SIZE;
	size--;
	return queue[front];
}

Queue::~Queue() //큐 객체 소멸 함수 
{
	delete[] queue;
}

