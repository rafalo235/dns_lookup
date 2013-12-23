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
    DNSServer serv("10.126.32.136");
    serv.connect();
    serv.translate("ekstraklasa.tv");
    serv.disconnect();
//    Request request;
//    request.addQuestion("www.onet.pl", 0x01);
//    request.addQuestion("www.90minut.pl", 0x01);

    return 0;
}

