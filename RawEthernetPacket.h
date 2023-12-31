#ifndef RAW_ETHERNET_PACKET_H
#define RAW_ETHERNET_PACKET_H

#include <string>
#include <iostream>
using namespace std;

const int DESTINATION_ADDRESS_POS = 16;
const int DESTINATION_ADDRESS_LENGTH = 12;
const int SOURCE_ADDRESS_POS = 28;
const int SOURCE_ADDRESS_LENGTH = 12;
const int TYPE_POS = 40;
const int TYPE_LENGTH = 4;
const int CRC_LENGTH = 8;

class RawEthernetPacket{
protected:

    string destinationAddress;
    string sourceAddress;
    string type;
    string CRC;
    string packet;
    void parsePacket();
public:
    RawEthernetPacket(const string& s);
    virtual void print();
};

#endif // RAW_ETHERNET_PACKET_H