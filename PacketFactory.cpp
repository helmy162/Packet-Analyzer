#include "PacketFactory.h"


std::string PacketFactory::getTypeIdentifier(const string& packet) {
    return packet.substr(ECPRI_TYPE_IDENTIFIER_START_POSITION, ECPRI_TYPE_IDENTIFIER_LENGTH);
}

RawEthernetPacket * PacketFactory::createPacket(const string& packetFrame) {
    if (getTypeIdentifier(packetFrame) == ECPRI_TYPE_IDENTIFIER) {
        return new ECPRIPacket(packetFrame);
    } else {
        return new RawEthernetPacket(packetFrame);
    }
}