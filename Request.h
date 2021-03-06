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
    Request(const char *);
    com_olejniczak_utils::dns_header getHeader();
    com_olejniczak_utils::dns_question *getQuestions(uint16_t *);
    uint16_t getHeaderId();
    void addQuestion(const char*, uint16_t);
    void setHeaderId(uint16_t id);
    virtual ~Request();
    char* marshal(int *);
private:
    com_olejniczak_utils::dns_header _header;
    com_olejniczak_utils::dns_question *_questions;
};

#endif	/* REQUEST_H */

