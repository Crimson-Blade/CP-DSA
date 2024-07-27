#include <iostream>
#include <vector>

int calculateDroppedPackets(std::vector<std::vector<int> >& requests, int max_packets, int rate) {
    int total_dropped_packets = 0;
    int packets_in_queue = 0;
    
    for (int i = 0; i < requests.size(); i++) {
        int current_time = requests[i][0];
        int current_packets = requests[i][1];
        
        // Remove packets from the queue based on the elapsed time
        if (current_time >= rate) {
            int packets_to_remove = (current_time / rate) * rate;
            packets_in_queue -= packets_to_remove;
        }
        
        // Add current packets to the queue
        packets_in_queue += current_packets;
        
        // Drop packets if the queue exceeds max_packets
        if (packets_in_queue > max_packets) {
            int dropped_packets = packets_in_queue - max_packets;
            total_dropped_packets += dropped_packets;
            packets_in_queue = max_packets;  // Reset the queue to max_packets
        }
    }
    
    return total_dropped_packets;
}

int main() {
    int n;
    std::cin>>n;
    std::vector<std::vector<int> > requests(n, std::vector<int>(2));
    std::cout << "Enter the requests:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> requests[i][0] >> requests[i][1];
    }
    
    std::cout << "Enter the value of max_packets: ";
    int max_packets;
    std::cin >> max_packets;
    
    std::cout << "Enter the value of rate: ";
    int rate;
    std::cin >> rate;
    
    int dropped_packets = calculateDroppedPackets(requests, max_packets, rate);
    
    std::cout << "Total dropped packets: " << dropped_packets << std::endl;
    
    return 0;
}
// 3 1 8 4 9 6 7 10 2




