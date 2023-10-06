#include "PacketFactory.h"


std::string PacketFactory::getTypeIdentifier(int typeIdentifierStartPosition,
                                             int typeIdentifierLength,
                                             const string& packet
                                             ) {
    return packet.substr(typeIdentifierStartPosition, typeIdentifierLength);
}

RawEthernetPacket * PacketFactory::createPacket(const string& packetFrame) {
    if (getTypeIdentifier(
            ECPRI_TYPE_IDENTIFIER_START_POSITION,
            ECPRI_TYPE_IDENTIFIER_LENGTH,
            packetFrame
            ) == ECPRI_TYPE_IDENTIFIER) {
        return new ECPRIPacket(packetFrame);
    } else {
        return new RawEthernetPacket(packetFrame);
    }
}