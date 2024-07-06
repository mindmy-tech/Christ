#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;       // Process ID
    int at;        // Arrival Time
    int bt;        // Burst Time
    int wt;        // Waiting Time
    int tat;       // Turnaround Time
} Process;

int compare(const void* a, const void* b) {
    Process* p1 = (Process*)a;
    Process* p2 = (Process*)b;
    return p1->at - p2->at;
}

void printGanttChart(Process* processes, int n) {
    printf("Gantt Chart:\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].bt; j++) {
            printf("-");
        }
        printf("|");
    }
    printf("\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].bt - 1; j++) {
            printf(" ");
        }
        printf("P%d", processes[i].pid);
    }
    printf("|\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process* processes = (Process*)malloc(n * sizeof(Process));

    printf("Enter the process ID, arrival time, and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].at, &processes[i].bt);
    }

    // Sort the processes based on arrival time
    qsort(processes, n, sizeof(Process), compare);

    // Calculate waiting time and turnaround time
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].at) {
            currentTime = processes[i].at;
        }
        processes[i].wt = currentTime - processes[i].at;
        currentTime += processes[i].bt;
        processes[i].tat = processes[i].wt + processes[i].bt;
    }

    // Print the Gantt chart
    printGanttChart(processes, n);

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = 0.0, avgTurnaroundTime = 0.0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].wt;
        avgTurnaroundTime += processes[i].tat;
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    free(processes);

    return 0;
}