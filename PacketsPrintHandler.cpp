#include "PacketsPrintHandler.h"

void PacketsPrintHandler::printPackets(const std::vector<RawEthernetPacket *> &packets) {
    for (int i = 0; i < packets.size(); ++i) {
        std::cout << "Packet # " << i << ":\n";
        packets[i]->print();
        std::cout << "\n*************************************************************"
                  << "****************************************************************"
                  << "****************************************************************"
                  << "*****************************************\n\n";
    }
}