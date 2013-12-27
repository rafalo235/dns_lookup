/* 
 * File:   BEResponse.cpp
 * Author: rafal.olejniczak
 * 
 * Created on 27 grudzień 2013, 13:12
 */

#include "BEResponse.h"
#include "utils.h"

BEResponse::BEResponse() {
}

BEResponse::BEResponse(const BEResponse& orig) {
}

com_olejniczak_utils::be_dns_header *BEResponse::getHeaderRef() {
    return &(this->_header);
}

BEResponse::~BEResponse() {
}

