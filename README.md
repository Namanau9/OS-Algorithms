# OS-Scheduling-Algorithms

This project implements several fundamental CPU scheduling algorithms in C. These algorithms are used in operating systems to manage the order in which processes are executed based on various criteria. The program demonstrates how to calculate waiting time, turnaround time, and optimize process scheduling using different methods.

## Algorithms Implemented

1. **First-Come, First-Served (FCFS) Scheduling**
   - Processes are executed in the order they arrive.
   - Simple scheduling method that calculates waiting and turnaround times.

2. **Shortest Job Next (SJN) Scheduling**
   - Also known as Shortest Job First (SJF).
   - Prioritizes processes with the shortest burst time.
   - Internally uses the FCFS scheduling function after sorting by burst time.

3. **Round Robin (RR) Scheduling**
   - A preemptive scheduling algorithm.
   - Processes are executed for a fixed time quantum in a cyclic order.
   - Ideal for time-sharing systems.

4. **Priority Scheduling**
   - Processes are executed based on their priority.
   - The process with the highest priority is scheduled first.
   - Uses FCFS internally after sorting by priority.
   

## License
This project is licensed under the MIT License - see the LICENSE file for details.
