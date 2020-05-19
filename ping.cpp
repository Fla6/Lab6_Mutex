#include <iostream>
#include <pthread.h>
#include "pingp.h"
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex;
char host[BUFF_LEN] = { 0, };

void * thread_func(void * arg)
{
    pthread_mutex_lock(&mutex);
    cout << "Thread " << pthread_self() << " work" << endl << endl;
    ping(host);
    cout << endl << "Thread " << pthread_self() << " done" << endl;
    pthread_mutex_unlock(&mutex);
    return NULL;
    
}

int main()
{
    pthread_t thread;
    cout << "Enter IP: ";
    cin.get(host, BUFF_LEN);
    cout << endl;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&thread, NULL, thread_func, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    if (pthread_join(thread, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    pthread_mutex_destroy(&mutex);
    return EXIT_SUCCESS;
}