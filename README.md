# CSE-316 Project
Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log into the system from 10am to 12am only. He wants to have separate requests queues for students and faculty. Implement a strategy for the same. The summary at the end of thesession should include the total time he spent on handling queries and average query time.

The main algorithm can be split into 3 main parts and 2 sub-parts of execution:

Execute the first process in the queue

Meanwhile, load the other processes that arrive

Push the current process to the end of the queue and execute the next process

If a process has finished executing, delete it from the process queue

Repeat until the number of processes running is 0.
