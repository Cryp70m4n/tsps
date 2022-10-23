# TSPS
TSPS - Triple Stack Process Scheduler

TSPS is an innovative implementation of process scheduler for kernels, this is just an demo showcase implemented using C++ this implementation has no real-world usage for now and should not be used in production (Real world implementation of this idea would be way more challinging than demo).

Why TSPS instead of priority queue? priority queue will execute all of the PIDs and sort them automatically that's true but if we use priority queue if we want to schedule some low-priority PIDs to be executed later (for example if we have 4 PIDs with priority 0 and 2 PIDs with priority 3 and then two new PIDs comes with priority 0 queue has to stop it's execution insert new elements sort them and then continue while with this implementation even if we are in execution time we can always put tasks into waiting stack. I know there are worksaround such as double queue and similar methods but this is just an demo idea and this idea could be expended easily we could even add queues into this method.)
