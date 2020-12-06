#pragma once
#include "Process.h"

class CpuSheduling
{
protected:
	Process* process;
	int num_of_processes;

	int sum_burst_time, sum_waiting_time, sum_turn_around_time;
	int smallest, smallest_arrival_time, smallest_burst_time;

public:
	~CpuSheduling()  { delete[] process; }

	virtual void InputProcesses() 
	{
		cout << "Enter number of processes: ";
		cin >> num_of_processes;

		process = new Process[num_of_processes + 1];
		for (int i = 0; i < num_of_processes; i++)
		{
			process[i].InputProcessInfo(i + 1);
			sum_burst_time += process[i].GetBurstTime();
		}
	}

	virtual void CalculateScheduleResult()
	{
		process[num_of_processes].SetBurstTime(9999);
		cout << "\nProcess\t| Arrival time\t| Burst time\t| Response time\t| Waiting time\t| Turn around time\n";
	}

	void CalculateSmallestProcess(int time)
	{
		smallest = num_of_processes;
		for (int j = 0; j < num_of_processes; ++j)
		{
			int arrival_time = process[j].GetArrivalTime();
			int burst_time = process[j].GetBurstTime();
			smallest_burst_time = process[smallest].GetBurstTime();

			if (arrival_time <= time && 
			    burst_time > 0 &&
			    burst_time < smallest_burst_time)	
			    smallest = j;
		}
		smallest_burst_time = process[smallest].GetBurstTime();
	}

	void OutputProcessInfo(int index)
	{
		process[index].PrintProcessInfo();
		sum_waiting_time += process[index].GetWaitingTime();
		sum_turn_around_time += process[index].GetTurnAroundTime();
	}

	void PrintAverageTime()
	{
		double avg_waiting_time = sum_waiting_time * 1.0 / num_of_processes;
		double avg_turn_around_time = sum_turn_around_time * 1.0 / num_of_processes;
		cout << "\n=> Average waiting time = " << avg_waiting_time;
		cout << "\n=> Average turn around time = " << avg_turn_around_time;
	}
};

