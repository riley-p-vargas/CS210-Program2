//
// Created by riley vargas on 10/16/2026.
//

#ifndef CS210_PROGRAM2_LOADBALANCER_H
#define CS210_PROGRAM2_LOADBALANCER_H


#include "request.h"
#include <queue>
#include <stack>
// STL for queue and priority_queue

class loadbalancer {
public:
    loadbalancer()
    {
        systemTime = 0;
    }

    int getTime ();
    void incTime ();
    void addRequest (request I);
    request getRequest () ;
    bool isRequestQueueEmpty();
    int getSize ();
private:
    int systemTime;
    queue <request> requestQueue;
    //priority_queue<request, vector<request>, MaxProcessTime> requestQueue; //priority_queue<request, vector<request>, MinProcessTime> requestQueue:
    //priority_queue<request, vector<request>, MaxPID> requestQueue:
    //stack<request> requestQueue;
};
    #endif
