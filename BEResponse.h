/* 
 * File:   BEResponse.h
 * Author: rafal.olejniczak
 *
 * Created on 27 grudzień 2013, 13:12
 */
#include "utils.h"


#ifndef BERESPONSE_H
#define	BERESPONSE_H

class BEResponse {
public:
    BEResponse();
    BEResponse(const BEResponse& orig);
    com_olejniczak_utils::be_dns_header *getHeaderRef();
    virtual ~BEResponse();
private:
    com_olejniczak_utils::be_dns_header _header;
    com_olejniczak_utils::dns_question *_questions;
    com_olejniczak_utils::dns_resource_rec *_answers;
};

#endif	/* BERESPONSE_H */

