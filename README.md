# Performance-Analysis-of-CPU-Scheduling-Algorithm_-Priority-and-SRT
Performance-Analysis-of-CPU-Scheduling-Priority-SRT-Algorithm
In this project, there are two algorithms(Priority & SRT) and we had implemented two modified algorithms to overcome from the problem of starvation of processes.

This system provides different types of services to the user.

User should be able to input required inputs according to the algorithm:

+ Process name, Arrival time, Burst time, and Priority in Priority Scheduling Algorithm.
+ Process name, Arrival time, and Burst time in shortest remaining time first.
## Preemptive Priority scheduling algorithm
As it is a preemptive algorithm so the processes which are having lower priorities will get preemptive and may there occurs the problem of starvation.

In this problem, the processes which will wait due to preemption might never get CPU again to execute them.

Highest the number lowest will be the priority.

## Shortest remaining time scheduling algorithm
This algorithm selects the smallest job and observes the incoming job if a new job with less time to execute then the currently executing job arrives, the current job is taken away and the CPU is assigned to the new shorter process.

## Priority scheduling algorithm with Aging technique
In aging technique, OS increases the priority of the processes which are in the waiting state for a long period, waiting for the CPU to allocate for execution.

## Modified SRT Scheduling Algorithm
When processes come to CPU for execution, processes must execute in SRT manner but when a process preempt more than three times then that process should execute after completion of currently executing process.

## System Requirements
### Hardware Requirement
+ Processor: Intel Pentium Dual Core or any latest processor
+ Processor Speed: 800 MHz or more
+ System Type: 32-bit or 64-bit
### Software Requirement
+ Operating System: Windows 7 or any latest
+ TurboC
