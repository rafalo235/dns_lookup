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
    com_olejniczak_utils::dns_header getHeader();
    uint16_t getHeaderId();
    void addQuestion(const char*, uint16_t);
    void setHeaderId(uint16_t id);
    virtual ~Request();
private:
    com_olejniczak_utils::dns_header _header;
    com_olejniczak_utils::dns_question *_questions;
};

#endif	/* REQUEST_H */

