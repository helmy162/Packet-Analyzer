#include "ECPRIPacket.h"
#include <vector>

int main() {
    freopen("input_packets", "r", stdin);
    freopen("output_packets", "w", stdout);

    vector<RawEthernetPacket*> packets;
    string packetFrame;
    while (cin >> packetFrame){
        if(packetFrame.substr(40, 4) == "AEFE")
            packets.push_back(new ECPRIPacket(packetFrame));
        else
            packets.push_back(new RawEthernetPacket(packetFrame));
    }

    for (int i = 0; i < packets.size(); ++i) {
        cout << "Packet # " << i << ":\n";
        packets[i]->print();
        cout << "\n*************************************************************"
             << "****************************************************************"
             << "****************************************************************"
             << "*****************************************\n\n";
    }
    return 0;
}


