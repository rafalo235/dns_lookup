/* 
 * File:   BEResponse.h
 * Author: rafal.olejniczak
 *
 * Created on 27 grudzień 2013, 13:12
 */

#ifndef BERESPONSE_H
#define	BERESPONSE_H

#include "utils.h"


class BEResponse {
public:
    BEResponse();
    BEResponse(const BEResponse& orig);
    virtual ~BEResponse();
private:
    com_olejniczak_utils::be_dns_header _header;
    com_olejniczak_utils::dns_question *_questions;
    
};

#endif	/* BERESPONSE_H */

