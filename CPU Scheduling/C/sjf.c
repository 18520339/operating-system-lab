#include <stdio.h>

int main()
{ 
	int arrival_time[10], burst_time[10];
	int response_time[10], waiting_time[10], turn_around_time[10];

	int num_of_processes, sum_burst_time = 0;
	int sum_waiting_time = 0, sum_turn_around_time = 0;

	printf("Enter number of processes: ");
	scanf("%d", &num_of_processes);

	for (int i = 0; i < num_of_processes; ++i)
	{
		printf("Enter arrival time and burst time of process %d: ", i + 1);
		scanf("%d%d", &arrival_time[i], &burst_time[i]);
		sum_burst_time += burst_time[i];
	}

	burst_time[9] = 9999;
	printf("\nProcess\t| Arrival time\t| Burst time\t| Response time\t| Waiting time\t| Turn around time\n");

	for (int i = 0; i < sum_burst_time;)
	{
		int smallest = 9;
		for (int j = 0; j < num_of_processes; ++j)
			if (arrival_time[j] <= i && burst_time[j] > 0 && burst_time[j] < burst_time[smallest]) smallest = j;
		if (smallest == 9) i++;

		turn_around_time[smallest] = i + burst_time[smallest] - arrival_time[smallest];
		waiting_time[smallest] = i - arrival_time[smallest];
		response_time[smallest] = waiting_time[smallest];

		sum_turn_around_time += turn_around_time[smallest];
		sum_waiting_time += waiting_time[smallest];
		printf(
			"P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", 
			smallest + 1, 
			arrival_time[smallest],
			burst_time[smallest],
			response_time[smallest],
			waiting_time[smallest],
			turn_around_time[smallest]
		);

		i += burst_time[smallest];
		burst_time[smallest] = 0;
	}
	
	printf("\n=> Average waiting time = %.2fs", sum_waiting_time * 1.0 / num_of_processes);
	printf("\n=> Average turn around time = %.2fs\n", sum_turn_around_time * 1.0 / num_of_processes);
	return 0;
}

