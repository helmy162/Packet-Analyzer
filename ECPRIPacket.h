#ifndef ECPRI_PACKET_H
#define ECPRI_PACKET_H

#include "RawEthernetPacket.h"

const int PROTOCOL_REVISION_POS = 44;
const int PROTOCOL_REVISION_LENGTH = 1;
const int CONCATENATION_INDICATOR_POS = 45;
const int MESSAGE_TYPE_POS = 46;
const int MESSAGE_TYPE_LENGTH = 2;
const int PAYLOAD_SIZE_POS = 48;
const int PAYLOAD_SIZE_LENGTH = 4;

const int RTC_ID_POS = 52;
const int RTC_ID_LENGTH = 4;
const int SEQ_ID_POS = 56;
const int SEQ_ID_LENGTH = 4;

struct Header{
    string protocolRevision;
    string messageType;
    string payloadSize;
    bool concatenationIndicator;
};

struct RealTimeControlData{
    string rtcId;
    string seqId;
};

class ECPRIPacket : public RawEthernetPacket{
private:
    Header header;
    RealTimeControlData realTimeControlData;

    int getHexParity(char digit);
protected:
    void parsePacket();
public:
    ECPRIPacket(const string& packet);
    virtual void print();
};

#endif // ECPRI_PACKET_H
