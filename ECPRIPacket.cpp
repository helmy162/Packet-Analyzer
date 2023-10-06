#include "ECPRIPacket.h"

int ECPRIPacket::getHexParity(char digit) {
    int integerVal;
    if('0' <= digit && digit <= '9')
        integerVal = digit - '0';
    else
        integerVal = digit - 'A' + 10;

    return integerVal % 2;
}

ECPRIPacket::ECPRIPacket(const std::string &packet) : RawEthernetPacket(packet) {
    parsePacket();
}

void ECPRIPacket::parsePacket() {
    this->header.protocolRevision = packet.substr(PROTOCOL_REVISION_POS, PROTOCOL_REVISION_LENGTH);
    this->header.messageType = packet.substr(MESSAGE_TYPE_POS, MESSAGE_TYPE_LENGTH);
    this->header.payloadSize = packet.substr(PAYLOAD_SIZE_POS,PAYLOAD_SIZE_LENGTH);
    this->header.concatenationIndicator = getHexParity(packet[CONCATENATION_INDICATOR_POS]);
    this->realTimeControlData.rtcId = packet.substr(RTC_ID_POS, RTC_ID_LENGTH);
    this->realTimeControlData.seqId = packet.substr(SEQ_ID_POS, SEQ_ID_LENGTH);
}

void ECPRIPacket::print() {
    cout << this->packet << '\n'
         << "CRC: " << this->CRC << '\n'
         << "Concatenation Indicator: " << this->header.concatenationIndicator << '\n'
         << "Destination Address: " << this->destinationAddress << '\n'
         << "Message Type: " << this->header.messageType << '\n'
         << "Payload Size: " << this->header.payloadSize << '\n'
         << "Protocol Version: " << this->header.protocolRevision << '\n'
         << "RTC ID: " << this->realTimeControlData.rtcId << '\n'
         << "Sequence ID: " << this->realTimeControlData.seqId << '\n'
         << "Source Address: " << this->sourceAddress << '\n'
         << "Type: " << this->type << '\n';
}