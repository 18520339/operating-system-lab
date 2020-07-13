#pragma once
#include "CpuSheduling.h"

class SJF : public CpuSheduling
{
public:
	void InputProcesses()
	{
		cout << "\n----------- SJF Scheduling -----------\n";
		CpuSheduling::InputProcesses();
	}

	void CalculateScheduleResult()
	{
		CpuSheduling::CalculateScheduleResult();
		for (int i = 0; i < sum_burst_time;)
		{
			CpuSheduling::CalculateSmallestProcess(i);
			if (smallest == num_of_processes) i++;

			process[smallest].SetBurstTime(0);
			smallest_arrival_time = process[smallest].GetArrivalTime();

			process[smallest].SetScheduleInfo(
				i - smallest_arrival_time,
				i - smallest_arrival_time,
				i + smallest_burst_time - smallest_arrival_time
			);
				
			OutputProcessInfo(smallest);
			i += smallest_burst_time;
		}
		CpuSheduling::PrintAverageTime();
	}
};

