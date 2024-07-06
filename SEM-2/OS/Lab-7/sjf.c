#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to sort the processes based on burst time
void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                // Swap the processes if they are out of order
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    // Calculate waiting time and turnaround time for each process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Calculate average waiting time and average turnaround time
    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;

    // Display the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Error: Maximum number of processes allowed is %d\n", MAX_PROCESSES);
        return 1;
    }

    struct Process processes[MAX_PROCESSES];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        processes[i].process_id = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on burst time
    sortProcesses(processes, n);

    // Calculate waiting time and turnaround time
    calculateTimes(processes, n);

    return 0;
}
