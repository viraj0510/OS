
#include <stdio.h>
#define MAX_PROCESSES 10
int main()
{
    int n, i, j;
    int burst_time[MAX_PROCESSES], remaining_time[MAX_PROCESSES];
    int process_order[MAX_PROCESSES], waiting_time[MAX_PROCESSES],
        turnaround_time[MAX_PROCESSES];
    int arrival_time[MAX_PROCESSES];
    int time_quantum;
    int completed = 0, current_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
        process_order[i] = i + 1;
    }
    printf("Enter arrival times for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }
    while (completed < n)
    {
        for (i = 0; i < n; i++)
        {
            if (arrival_time[i] <= current_time && remaining_time[i] > 0)
            {
                if (remaining_time[i] <= time_quantum)
                {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    completed++;
                    turnaround_time[i] = current_time - arrival_time[i];
                    waiting_time[i] = turnaround_time[i] - burst_time[i];
                }
                else
                {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
            }
        }
    }
    double avg_waiting_time = 0, avg_turnaround_time = 0;
    for (i = 0; i < n; i++)
    {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
 printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround
Time\n");
 for (i = 0; i < n; i++)
 {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process_order[i], burst_time[i],
               arrival_time[i], waiting_time[i], turnaround_time[i]);
 }
 printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
 printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
 return 0;
}
