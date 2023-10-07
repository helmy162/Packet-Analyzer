#ifndef PACKET_FACTORY_H
#define PACKET_FACTORY_H

#include "ECPRIPacket.h"

const int ECPRI_TYPE_IDENTIFIER_START_POSITION = 40;
const int ECPRI_TYPE_IDENTIFIER_LENGTH = 4;
const string ECPRI_TYPE_IDENTIFIER = "AEFE";

class PacketFactory {
public:
    static RawEthernetPacket* createPacket(const std::string& packetFrame);
private:
    static string getTypeIdentifier(const string& packet);
};

#endif // PACKET_FACTORY_H