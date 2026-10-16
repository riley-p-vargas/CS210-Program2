/* riley vargas
* CS210-05
 */
//
// Created by riley vargas on 10/16/2026.
//
#include "loadbalancer.h"
#include "request.h"
#include "webserver.cpp"

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

}

