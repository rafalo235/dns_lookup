/* 
 * File:   Request.h
 * Author: rafal.olejniczak
 *
 * Created on 16 grudzień 2013, 16:17
 */

#ifndef REQUEST_H
#define	REQUEST_H

#include "utils.h"

class Request {
public:
    Request();
    Request(const Request& orig);
    void setHeaderId(uint16_t id);
    virtual ~Request();
private:
    com_olejniczak_utils::dns_header _header;
};

#endif	/* REQUEST_H */

