#ifndef PACKETS_PRINT_HANDLER_H
#define PACKETS_PRINT_HANDLER_H

#include "ECPRIPacket.h"
#include <vector>
class PacketsPrintHandler {
public:
    static void printPackets(const std::vector<RawEthernetPacket*>& packets);
};

#endif // PACKETS_PRINT_HANDLER_H