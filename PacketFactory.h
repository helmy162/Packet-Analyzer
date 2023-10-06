#include "ECPRIPacket.h"

const int ECPRI_TYPE_IDENTIFIER_START_POSITION = 40;
const int ECPRI_TYPE_IDENTIFIER_LENGTH = 4;
const string ECPRI_TYPE_IDENTIFIER = "AEFE";

class PacketFactory {
public:
    static RawEthernetPacket* createPacket(const std::string& packetFrame);
private:
    static string getTypeIdentifier(int typeIdentifierStartPosition, int typeIdentifierLength, const string& packet);
};