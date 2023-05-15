#ifndef DATA_STRUCT
#define DATA_STRUCT

#include <iostream>

using namespace std;

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

#endif