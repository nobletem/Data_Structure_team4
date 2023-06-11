#ifndef DATA_STRUCT
#define DATA_STRUCT

#include <iostream>
#include "Params.h"

using namespace std;

/******************************************************************
* Queue
******************************************************************/

class Queue
{
private:
	unsigned int* queue;
	unsigned int size;
	int front;
	int rear;

public:
	Queue(); //큐 객체를 생성할 때 호출되는 함수/큐가 비어있음을 의미하도록 변수 초기화

	bool Qempty(); //큐가 비어있는지 확인할 함수

	bool Qfull(); //큐가 차있는지 확인할 함수

	unsigned int getSize();

	void addQueue(int value); //큐가 꽉 차있는지 확인 후 큐에 원소 추가 

	unsigned int deleteQueue(); //큐가 비어있는지 확인 후 원소 리턴

	~Queue(); //큐 객체 소멸 함수 

};

/******************************************************************
* s_Queue
******************************************************************/
class s_Queue
{
private:
	string* queue;
	unsigned int size;
	int front;
	int rear;

public:
	s_Queue(); //큐 객체를 생성할 때 호출되는 함수/큐가 비어있음을 의미하도록 변수 초기화

	bool Qempty(); //큐가 비어있는지 확인할 함수

	bool Qfull(); //큐가 차있는지 확인할 함수

	unsigned int getSize();

	void addQueue(string value); //큐가 꽉 차있는지 확인 후 큐에 원소 추가 

	string deleteQueue(); //큐가 비어있는지 확인 후 원소 리턴

	~s_Queue(); //큐 객체 소멸 함수 

};

/******************************************************************
* Priotrity_Queue
******************************************************************/
// Node
struct Node {
private:
    unsigned int key;
public:
	Node();

    Node(unsigned int _key );

    unsigned int getKey();

    void setKey(unsigned int _key);
};

// Min heap
class MinHeap {
private:
    Node node[MAX_ELEMENT];
    int size;  
public:
    MinHeap();

    Node& getParent(int index);

    Node& getLeftChild(int index);

    Node& getRightChild(int index);

    bool isEmpty();

    bool isFull();

    bool insert(unsigned int key);

	unsigned int remove();

};
// HeapSort

void heapSort(unsigned int a[], int n);

/******************************************************************
* SortandSelect
******************************************************************/

class SortandSelect {
private:
	void swap(int* int1, int* int2);
	int partition(int arr[], int left, int right);
	void merge(int array[], int const left, int const mid, int const right);
public:
	void quickSort(int arr[], int left, int right);
	void mergeSort(int array[], int const left, int const right);
	int quickSelect(int arr[], int left, int right, int k);
};

//우선순위 큐
class PriorityQueue
{
private:
	Queue queue;
public:
	void pqaddqueue(int value); //값을 큐에 추가
	unsigned int pqdequeue(); //함수는 큐에서 값을 제거하며 반환
	int pqgetSize(); //큐의 크기를 반환
	bool pqempty(); //함수가 비어있는지의 여부 확인
	~PriorityQueue();
};
#endif
