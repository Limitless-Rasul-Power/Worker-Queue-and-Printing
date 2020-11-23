#pragma once
#include "Worker.h"
class WorkerQueue
{

private:
	Worker** workers;
	unsigned short capacity_of_workers;
	unsigned short rear;
	unsigned short front{ 0 };

public:

	WorkerQueue();

	WorkerQueue(const WorkerQueue&) = default;

	WorkerQueue& operator = (const WorkerQueue& other);

	explicit WorkerQueue(const unsigned short& capacity_of_workers);

	void Enqueue(Worker* const& added);

	Worker* Dequeue();

	Worker* Peek() const;

	unsigned short Size() const;

	bool Is_full() const;

	bool Is_empty() const;

	void Set_capacity_of_workers(const short& capacity_of_workers);
	unsigned short Get_capacity_of_workers() const;

	void Set_workers();
	Worker** Get_workers() const;

	void Equal_workers(const short& capacity_of_workers);


	~WorkerQueue();
};