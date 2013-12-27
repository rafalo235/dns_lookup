/* 
 * File:   BERequest.h
 * Author: rafal.olejniczak
 *
 * Created on 27 grudzień 2013, 09:10
 */

#include "utils.h"
#include "Request.h"
#include <stdint.h>

#ifndef BEREQUEST_H
#define	BEREQUEST_H

class BERequest {
public:
    BERequest(Request &);
//    BERequest(const BERequest& orig);
    char* marshal(int *);
    virtual ~BERequest();
private:
    com_olejniczak_utils::be_dns_header _header;
    com_olejniczak_utils::dns_question *_questions;
    uint16_t _q_amount;
};

#endif	/* BEREQUEST_H */

