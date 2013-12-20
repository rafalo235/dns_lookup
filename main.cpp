/* 
 * File:   main.cpp
 * Author: rafal.olejniczak
 *
 * Created on 16 grudzień 2013, 13:20
 */

#include <cstdlib>
#include <cstdio>
#include <sstream>

#include "DNSServer.h"
#include "Request.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    DNSServer serv("127.0.0.1");
    Request request;

    return 0;
}

