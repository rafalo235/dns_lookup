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
    DNSServer serv("10.230.5.6");
    serv.connect();
    serv.translate("google.pl");
    serv.disconnect();
//    Request request;
//    request.addQuestion("www.onet.pl", 0x01);
//    request.addQuestion("www.90minut.pl", 0x01);

    return 0;
}

