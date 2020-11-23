#pragma once
#include "Worker_Queue.h"
class Printer
{

private:
	WorkerQueue worker_queue;

public:

	Printer();
	
	Printer(const WorkerQueue& worker_queue);

	void Set_worker_queue(const WorkerQueue& worker_queue);
	WorkerQueue Get_worker_queue() const;

	void Start();
};
void Goodbye_message();