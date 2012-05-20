/*
 * test.cpp
 *
 *  Created on: May 19, 2012
 *      Author: aka_w
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "Test.h"

extern "C" {
#include <pthread.h>
}

using namespace std;


#define P_SIZE 4

template<typename T>
class ObjList {
typedef typename std::vector<T> container;
public:
    ObjList(size_t sz=0) {
        cout << "Constructor" << endl;
        data = new container(sz);
    }

    ~ObjList() {
        delete data;
    }

    size_t size();

//private:
	container *data;
};


template<typename T>
size_t ObjList<T>::size(){
    return data->size();
};

static void* start(void*) {
    cout << "I'm thread" << endl;
    return NULL;
}

static int init_thread(pthread_t pptr) {
    pthread_create(&pptr, NULL, start, NULL);
    return 0;
}

int main(int argc, char* argv[]) {
	cout << "Test version: " << Test_VERSION_MAJOR << "." << Test_VERSION_MINOR << " running." << endl;
	ObjList<pthread_t> d(4);
	for_each(d.data->begin(), d.data->end(), init_thread);

	return 0;
}


