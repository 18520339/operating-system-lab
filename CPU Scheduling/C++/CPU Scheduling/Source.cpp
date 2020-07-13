#include "SJF.h"
#include "SRTF.h"

int main()
{
	CpuSheduling* cpuScheduling = new CpuSheduling();
	int choice, exit = 0;

	while (!exit)
	{
		cout << "\n----------- MENU -----------\n";
		cout << "1. Shortest Job First (SJF)\n";
		cout << "2. Shortest Remaining Time First (SRTF)\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				cpuScheduling = new SJF();
				break;
			case 2:
				cpuScheduling = new SRTF();
				break;
			default:
				break;
		}

		cpuScheduling->InputProcesses();
		cpuScheduling->CalculateScheduleResult();

		cout << "\nExit ??? (1/0): ";
		cin >> exit;
	}
	
	delete cpuScheduling;
	return 0;
}