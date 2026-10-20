/* riley vargas
* CS210-05
 */
//
// Created by riley vargas on 10/16/2026.
//
#include "loadbalancer.h"
#include "request.h"
#include "webserver.cpp"
#include "loadbalancer.cpp"

#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
using namespace std;

const int NUM_SERVERS = 5;
static int ps = 0;
request createRandomRequest() {
    stringstream ips,ipd;
    request r;
    ips << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." <<(rand() % 256);
    ipd << (rand() % 256) << "." << rand() % 256 << "." << rand() % 256 << "." << rand() % 256;
    r.source = ips.str();
    r.destination = ipd.str();
    r.processTime = (rand() % 500);
    r.pid = ++ps;
    return r;
}

int main() {
    srand(time(0));

    loadbalancer lb;

    for (int i = 0; i < 10; ++i) {
        request r = createRandomRequest();
        lb.addRequest(r);
    }

    webserver webarray[NUM_SERVERS];
    for (int i = 0; i < NUM_SERVERS; ++i) {
        webserver w((char) (i + 65));
        webarray[i] = w;
        webarray[i].addRequest(lb.getRequest(),lb.getTime());
    }

    while (lb.getTime() < 10000) {
        int currTime = lb. getTime();
        int size = lb.getSize();
        // check each webserver if it's done
        if(webarray[currTime % NUM_SERVERS].isRequestDone(currTime)){
            request r = webarray[currTime % NUM_SERVERS].getRequest();
            //print
            cout << "Finished at " << currTime <<webarray [currTime % NUM_SERVERS].getName();
            cout << " pid " << r.pid << " / " << size << " process time was " << r.processTime;
            cout << " processed request from " << r.source << r.destination;
            cout << endl;

            webarray[currTime % NUM_SERVERS].addRequest(lb.getRequest(),currTime);
        }
        if (rand() % 10 == 0) {
            request r = (createRandomRequest());
            lb.addRequest(r);
        }
        lb.incTime();
    }
}
