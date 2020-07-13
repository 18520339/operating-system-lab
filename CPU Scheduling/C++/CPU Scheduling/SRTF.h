#pragma once
#include "CpuSheduling.h"

class SRTF : public CpuSheduling
{
public:
	void InputProcesses()
	{
		cout << "\n----------- SRTF Scheduling -----------\n";
		CpuSheduling::InputProcesses();
	}

	void CalculateScheduleResult()
	{
		CpuSheduling::CalculateScheduleResult();
		for (int i = 0; i < num_of_processes; ++i)
			process[i].SetScheduleInfo(-1, 0, 0);

		for (int i = 0; i < sum_burst_time; ++i)
		{
			CpuSheduling::CalculateSmallestProcess(i);
			if (smallest == num_of_processes) sum_burst_time++;

			for (int j = 0; j < num_of_processes; ++j)
			{
				int arrival_time = process[j].GetArrivalTime();
				int burst_time = process[j].GetBurstTime();
				int waiting_time = process[j].GetWaitingTime();

				if (arrival_time <= i && burst_time > 0 && j != smallest)
					process[j].SetWaitingTime(waiting_time + 1);
			}

			smallest_burst_time--;
			process[smallest].SetBurstTime(smallest_burst_time);
			smallest_arrival_time = process[smallest].GetArrivalTime();

			if (process[smallest].GetResponseTime() == -1)
				process[smallest].SetResponseTime(i - smallest_arrival_time);

			if (smallest_burst_time == 0)
				process[smallest].SetTurnAroundTime(i - smallest_arrival_time + 1);
		}

		for (int i = 0; i < num_of_processes; ++i)
			OutputProcessInfo(i);
		CpuSheduling::PrintAverageTime();
	}
};

