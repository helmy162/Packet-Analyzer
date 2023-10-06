#include "RawEthernetPacket.h"

RawEthernetPacket::RawEthernetPacket(const std::string &packet) {
    this->packet = packet;
    parsePacket();
}

void RawEthernetPacket::parsePacket() {
    this->destinationAddress = packet.substr(DESTINATION_ADDRESS_POS, DESTINATION_ADDRESS_LENGTH);
    this->sourceAddress = packet.substr(SOURCE_ADDRESS_POS, SOURCE_ADDRESS_LENGTH);
    this->type = packet.substr(TYPE_POS, TYPE_LENGTH);
    this->CRC = packet.substr(packet.length() - CRC_LENGTH, CRC_LENGTH);
}

void RawEthernetPacket::print() {
    cout << this->packet << '\n'
         << "CRC: " << this->CRC << '\n'
         << "Destination Address: " << this->destinationAddress << '\n'
         << "Source Address: " << this->sourceAddress << '\n'
         << "Type: " << this->type << '\n';
}

