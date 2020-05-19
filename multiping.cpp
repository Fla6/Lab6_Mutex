#include <iostream>
#include <unistd.h>
#include <fstream>
#include "pingp.h"
#include <pthread.h>
using namespace std;

pthread_mutex_t mutex;
char host[BUFF_LEN] = { 0, };

void * thread_func(void * arg)
{
    pthread_mutex_lock(&mutex);
    cout << "Thread " << pthread_self() << " work" << "\n";
    ping(host);
    cout << "Thread " << pthread_self() << " done" << endl << "\n";
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_t thread;
    ifstream fout;
    fout.open("input2.txt");
    pthread_mutex_init(&mutex, NULL);
    while (!fout.eof())
    {
        fout >> host;
        if (pthread_create(&thread, NULL, thread_func, NULL) != 0)
        {
            return EXIT_FAILURE;
        }
    }
    if (pthread_join(thread, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}