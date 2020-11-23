#include <iostream>
#include <assert.h>
#include "Worker_Queue.h"

WorkerQueue::WorkerQueue():workers(nullptr), capacity_of_workers(0), rear(0), front(0)
{}

WorkerQueue& WorkerQueue::operator = (const WorkerQueue & other)
{
	this->workers = new Worker * [other.rear];
	this->rear = other.rear;
	this->capacity_of_workers = other.capacity_of_workers;
	this->front = other.front;

	for (unsigned short i = 0; i < this->rear; i++)
	{
		this->workers[i] = new Worker;
		this->workers[i][0] = other.workers[i][0];
	}

	return *this;
}

WorkerQueue::WorkerQueue(const unsigned short& capacity_of_workers)
{
	Set_capacity_of_workers(capacity_of_workers);
	Set_workers();
}

void WorkerQueue::Enqueue(Worker* const& added)
{
	assert(added && !Is_full() && "Added Worker is Nullptr!");
	this->workers[rear] = added;
	rear++;
}

Worker* WorkerQueue::Dequeue()
{
	assert(!Is_empty() && "Queue Is Empty!");

	Worker* deleted_worker = this->workers[front];

	Worker** temp = new Worker * [Size() - 1];

	for (unsigned short i = 0; i < Size() - 1; i++)
			temp[i] = this->workers[i + 1];

	delete[] workers;
	this->workers = temp;
	temp = nullptr;
	rear--;

	return deleted_worker;
}

Worker* WorkerQueue::Peek() const
{
	return workers[front];
}

unsigned short WorkerQueue::Size() const
{
	return rear;
}

bool WorkerQueue::Is_full() const
{
	return Size() == capacity_of_workers;
}

bool WorkerQueue::Is_empty() const
{
	return Size() == 0;
}

void WorkerQueue::Set_capacity_of_workers(const short& capacity_of_workers)
{
	assert(capacity_of_workers > 0 && "Number of workers is 0!");
	this->capacity_of_workers = capacity_of_workers;
}

unsigned short WorkerQueue::Get_capacity_of_workers() const
{
	return capacity_of_workers;
}

void WorkerQueue::Set_workers()
{
	this->workers = new Worker * [Get_capacity_of_workers()];
}

void WorkerQueue::Equal_workers(const short& capacity_of_workers)
{
	this->workers = new Worker * [capacity_of_workers];
}

Worker** WorkerQueue::Get_workers() const
{
	return workers;
}

WorkerQueue::~WorkerQueue()
{
	if (!Is_empty())
	{
		for (unsigned short i = 0; i < Size(); i++)
			delete this->workers[i];

		delete[] this->workers;
	}
}