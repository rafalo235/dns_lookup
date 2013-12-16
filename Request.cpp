/* 
 * File:   Request.cpp
 * Author: rafal.olejniczak
 * 
 * Created on 16 grudzień 2013, 16:17
 */

#include "Request.h"

Request::Request() {
}

Request::Request(const Request& orig) {
}

void Request::setHeaderId(uint16_t id) {
    this->_header->id = id;
}

Request::~Request() {
}

