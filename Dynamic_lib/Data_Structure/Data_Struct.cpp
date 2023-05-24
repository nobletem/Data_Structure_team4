#include <iostream>
#include "params.h"
#include "Data_Struct.h"
using namespace std;


/******************************************************************
* Queue
******************************************************************/

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
        cout << "큐가 모두 차있습니다"; //예외처리
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
        cout << "큐가 모두 비어있습니다"; //예외처리
        return 0;
    }
    else
    {
        int frontelement = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        size--;
        return frontelement;
    }
}

Queue::~Queue() //큐 객체 소멸 함수 
{
    delete[] queue;
}


/******************************************************************
* s_Queue
******************************************************************/

s_Queue::s_Queue() //큐 객체를 생성할 때 호출되는 함수/큐가 비어있음을 의미하도록 변수 초기화
{
    this->front = -1;
    this->rear = -1;
    this->size = 0;
    queue = new string[MAX_QUEUE_SIZE]; //큐의 원소를 저장할 동적 배열 
}

bool s_Queue::Qempty() //큐가 비어있는지 확인할 함수
{
    return size == 0;
}

bool s_Queue::Qfull() //큐가 차있는지 확인할 함수
{
    if (size == MAX_QUEUE_SIZE)
        return true;
    else
        return false;
}

unsigned int s_Queue::getSize()
{
    return size;
}

void s_Queue::addQueue(string value) //큐가 꽉 차있는지 확인 후 큐에 원소 추가 
{
    if (Qfull() == true)
    {
        cout << "큐가 모두 차있습니다"; //예외처리
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

string s_Queue::deleteQueue() //큐가 비어있는지 확인 후 원소 제거 
{
    if (Qempty())
    {
        string a;
        cout << "큐가 모두 비어있습니다"; //예외처리
        return a;
    }
    else
    {
        string frontelement = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        size--;
        return frontelement;
    }
}

s_Queue::~s_Queue() //큐 객체 소멸 함수 
{
    delete[] queue;
}



/******************************************************************
* Sort and Select
******************************************************************/
// Quick Sort

void SortandSelect::swap(int* int1, int* int2) { // 포인터를 사용한 swap 함수
    int temp = *int1;
    *int1 = *int2;
    *int2 = temp;
}

int SortandSelect::partition(int arr[], int left, int right) {
    int pivot = arr[right]; // 마지막 원소를 pivot으로 선언
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) { // 현재 원소가 pivot보다 작을때마다 작동
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void SortandSelect::quickSort(int arr[], int left, int right) { // quickSort 함수 선언
    if (left < right) {
        int index = partition(arr, left, right); // index 선언과 함께 index를 맞는 위치에 정렬
        quickSort(arr, left, index - 1);  // index 전에 있는 원소 정렬
        quickSort(arr, index + 1, right); // index 후에 있는 원소 정렬
    }
}

//Merge Sort
void SortandSelect::merge(int array[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto* leftArray = new int[subArrayOne]; // 임시 배열 선언
    auto* rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) { // 왼쪽에 남은 원소 복사
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) { // 오른쪽에 남은 원소 복사
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray; // 임시 배열 삭제
    delete[] rightArray;
}

void SortandSelect::mergeSort(int array[], int const left, int const right) {
    if (left >= right)
        return;

    auto mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

// Quick Select
// 배열안 모든 원소들은 구별된다 (유일하고 중복되지 않는다)
int SortandSelect::quickSelect(int arr[], int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
        int index = partition(arr, left, right); // quickSort와 같은 원리로 계산
        if (index - left == k - 1) {
            return arr[index];
        }
        if (index - left > k - 1) {
            return quickSelect(arr, left, index - 1, k);
        }
        return quickSelect(arr, index + 1, right, k - index + left - 1); // k-1이 index-left보다 클때
    }
    return -1; // k가 배열 index보다 클 경우
}