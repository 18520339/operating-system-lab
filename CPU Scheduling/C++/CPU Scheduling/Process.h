#pragma once
#include <iostream>
using namespace std;

class Process
{
	private:
		int pid, arrival_time, burst_time, burst_time_copy;
		int response_time, waiting_time, turn_around_time;

	public:
		int GetArrivalTime() { return arrival_time; }
		int GetBurstTimeCopy () { return burst_time_copy; }

		int GetBurstTime() { return burst_time; }
		void SetBurstTime(int value) { burst_time = value; };

		int GetResponseTime() { return response_time; }
		void SetResponseTime(int value) { response_time = value; };

		int GetWaitingTime() { return waiting_time; }
		void SetWaitingTime(int value) { waiting_time = value; };

		int GetTurnAroundTime() { return turn_around_time; }
		void SetTurnAroundTime(int value) { turn_around_time = value; };

		void InputProcessInfo(int pid)
		{
			this->pid = pid;
			cout << "Enter arrival time and burst time of process " << pid << ": ";
			cin >> arrival_time >> burst_time;
			burst_time_copy = burst_time;
		}

		void SetScheduleInfo(int response_time, int waiting_time, int turn_around_time)
		{
			this->response_time = response_time;
			this->waiting_time = waiting_time;
			this->turn_around_time = turn_around_time;
		}

		void PrintProcessInfo()
		{
			cout << "P" << pid		 << "\t|\t"
				 << arrival_time	 << "\t|\t"
				 << burst_time_copy  << "\t|\t"
				 << response_time	 << "\t|\t"
				 << waiting_time	 << "\t|\t"
				 << turn_around_time << endl;
		}
};

