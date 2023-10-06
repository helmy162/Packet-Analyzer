#include <string>
#include <iostream>
using namespace std;

class RawEthernetPacket{
protected:
    const int DESTINATION_ADDRESS_POS = 16;
    const int DESTINATION_ADDRESS_LENGTH = 12;
    const int SOURCE_ADDRESS_POS = 28;
    const int SOURCE_ADDRESS_LENGTH = 12;
    const int TYPE_POS = 40;
    const int TYPE_LENGTH = 4;
    const int CRC_LENGTH = 8;

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