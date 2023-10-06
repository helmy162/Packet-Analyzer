#include "PacketFactory.h"
#include "PacketsPrintHandler.h"

int main() {
    freopen("input_packets", "r", stdin);
    freopen("my_output_packets", "w", stdout);

    vector<RawEthernetPacket*> packets; // Vector to store packet objects
    string packetFrame; // To store each packet data from input

    // getting packets from the input_packets file
    while (cin >> packetFrame){
        RawEthernetPacket* packet = PacketFactory::createPacket(packetFrame);
        packets.push_back(packet);
    }

    // printing the parsed data in the output file
    PacketsPrintHandler::printPackets(packets);

    // free the allocated memory
    for (RawEthernetPacket* packet : packets) {
        delete packet;
    }

    return 0;
}


