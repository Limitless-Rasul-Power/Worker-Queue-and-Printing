#include <iostream>
#include "Printer.h"
#include <windows.h>

Printer::Printer()
{}

Printer::Printer(const WorkerQueue& worker_queue)
{
	Set_worker_queue(worker_queue);
}

void Printer::Set_worker_queue(const WorkerQueue& worker_queue)
{
	this->worker_queue = worker_queue;
}

WorkerQueue Printer::Get_worker_queue() const
{
	return worker_queue;
}

void Printer::Start()
{
	COORD c{ 47, 10 };
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	for (unsigned short i = 0; !worker_queue.Is_empty(); i++)
	{
		for (unsigned short j = 0; j < worker_queue.Get_workers()[0]->Get_page_count(); j++)
		{
			system("CLS");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
			std::cout << '#' << i + 1 << " Xerox Operation is " << worker_queue.Get_workers()[0]->Get_name() << "'s";
			c.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
			std::cout << "Page Count = " << worker_queue.Get_workers()[0]->Get_page_count();
			c.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
			if (j < worker_queue.Get_workers()[0]->Get_page_count() / 2)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

			std::cout << "Copied Page Number: " << j + 1;
			c.Y -= 2;
			Sleep(100);
		}
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		std::cout << worker_queue.Get_workers()[0]->Get_name() << "'s Xerox is Finished, We going to take next Order!\n\n\n";
		Sleep(800);
		worker_queue.Dequeue();
	}
	system("CLS");
}

void Goodbye_message()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 47, 10 });
	std::cout << "All Xeroxs done Goodbye See You Soon!\n";
}