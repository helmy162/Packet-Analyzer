#include "PacketFactory.h"
#include <vector>

int main() {
    freopen("input_packets", "r", stdin);
    freopen("my_output_packets", "w", stdout);

    vector<RawEthernetPacket*> packets; // Vector to store packet objects
    string packetFrame; // To store each packet data from input

    while (cin >> packetFrame){
        RawEthernetPacket* packet = PacketFactory::createPacket(packetFrame);
        packets.push_back(packet);
    }

    for (int i = 0; i < packets.size(); ++i) {
        cout << "Packet # " << i << ":\n";
        packets[i]->print();
        cout << "\n*************************************************************"
             << "****************************************************************"
             << "****************************************************************"
             << "*****************************************\n\n";
    }

    // free the allocated memory
    for (RawEthernetPacket* packet : packets) {
        delete packet;
    }

    return 0;
}


