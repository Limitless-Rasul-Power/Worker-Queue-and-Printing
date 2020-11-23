#include <iostream>
#include "Printer.h"

using namespace std;

short Worker::id = 0;

int main()
{
	Worker* w1 = new Worker("Kate", "Winston", 24, 20);
	Worker* w2 = new Worker("Charles", "Frederick", 36, 30);
	Worker* w3 = new Worker("Marc", "Benioff", 44, 40);

	WorkerQueue wq(10);

	wq.Enqueue(w1);
	wq.Enqueue(w2);
	wq.Enqueue(w3);

	Printer xerox(wq);
	xerox.Start();
	Goodbye_message();

	system("pause");
	return 0;
}