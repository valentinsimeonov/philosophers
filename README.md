Tutorials:

1. Threads: https://www.youtube.com/watch?v=d9s_d28yJq0&ab_channel=CodeVault

2. Race Conditions: https://www.youtube.com/watch?v=FY9livorrJI&ab_channel=CodeVault

3. Mutex: https://www.youtube.com/watch?v=oq29KUy29iQ&ab_channel=CodeVault

4. Create Threads in a Loop: https://www.youtube.com/watch?v=xoXzp4B8aQk&ab_channel=CodeVault

5. Return Value from Thread: https://www.youtube.com/watch?v=ln3el6PR__Q&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=7



Steps Necessary in Building the Program:
1. Add "-pthread" to tasks.json File to be able to Create and Join Threads, otherwise must use the -pthread Flag when Compiling (gcc -g -pthread file.c)

2. Argument Checkers
3. 



Random:
1. gcc -S filename.c  Compiles C Code into Assembly Code(.s file)



Questions:
1. In init.c Line 62 - Why pthread_mutex_init(&(settings->m_print), NULL); ?

2. In init.c Line 63 - Why  settings->to_phils 

3. How Do you Print a variable in a Struct?
	printf("%d", table->start); --- Does not Work

4. In init.c Line 46 - Why
	pthread_mutex_init(&(ph->m_eat), NULL);

5. In init.c Line 25 - Why
	pthread_mutex_t *