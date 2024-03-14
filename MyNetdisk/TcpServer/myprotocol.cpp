#include "myprotocol.h"

#include <cstdlib>
#include <cstring>

PDU *mkPDU(uint MsgLength)
{
    uint PDULength = sizeof(PDU) + MsgLength;
    PDU *pdu = (PDU*)malloc(PDULength);
    if(pdu == NULL){
        exit(EXIT_FAILURE);
    }
    memset(pdu,0,PDULength);    // 将分配的内存清零
    pdu->PDULength = PDULength;
    pdu->MsgLength = MsgLength;
    return pdu;
}
