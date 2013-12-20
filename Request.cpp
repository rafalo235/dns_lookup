/* 
 * File:   Request.cpp
 * Author: rafal.olejniczak
 * 
 * Created on 16 grudzień 2013, 16:17
 */

#include <cstdio>
#include "Request.h"

Request::Request() {
    this->_header.id = 0x0000;
    this->_header.qr = 0x0;
    this->_header.opcode = 0x00;
    this->_header.aa = 0x0; // set by server
    this->_header.tc = 0x0; // set by server
    this->_header.rd = 0x1;
    this->_header.ra = 0x0; // set by server
    this->_header.z = 0x00; // reserved
    this->_header.r_code = 0x00; // response code set by server
    this->_header.qdcount = 0x0000;
    this->_header.ancount = 0x0000; // set by server
    this->_header.nscount = 0x0000; // set by server
    this->_header.arcount = 0x0000; // set by server
    this->_questions = NULL;
}

Request::Request(const Request& orig) {
    //this->_header = orig.getHeader();
}

void Request::setHeaderId(uint16_t id) {
    this->_header.id = id;
}

void Request::addQuestion(const char *name, uint16_t type) {
    com_olejniczak_utils::dns_question q;
    q.name.length = 0;
    
    q.type = type;
    q.net_class = 0x0001; // IN - Internet
    
}

com_olejniczak_utils::dns_header Request::getHeader() {
    return this->_header;
}

Request::~Request() {
}

