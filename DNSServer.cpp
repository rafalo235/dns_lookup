/* 
 * File:   DNSServer.cpp
 * Author: rafal.olejniczak
 * 
 * Created on 16 grudzień 2013, 13:21
 */

#include <cstdio>
#include "utils.h"

#include "DNSServer.h"

DNSServer::DNSServer() {
    this->_address = 0;
}

DNSServer::DNSServer(int address) {
    this->_address = address;
}

DNSServer::DNSServer(const char* address) {
    this->_address = com_olejniczak_utils::convert_addr_to_int(address);
    
    
//    this->_address *= 256;
}

DNSServer::DNSServer(const DNSServer& orig) {
}

DNSServer::~DNSServer() {
}

int DNSServer::translate(const char* addr) {
    return 0;
}

