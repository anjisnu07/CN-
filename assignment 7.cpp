#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate network ID, subnet mask, total number of IP addresses, and limited broadcast ID
void calculate(char *ip_address) {
    unsigned int ip[4];
    sscanf(ip_address, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Calculate default subnet mask for Class C network
    unsigned int subnet_mask[4] = {255, 255, 255, 0};

    // Calculate network ID
    unsigned int network_id[4];
    for (int i = 0; i < 4; i++) {
        network_id[i] = ip[i] & subnet_mask[i];
    }

    // Calculate total number of IP addresses
    unsigned int total_ips = 1;
    for (int i = 0; i < 4; i++) {
        if (subnet_mask[i] != 255) {
            total_ips *= (subnet_mask[i] + 1);
        }
    }
    total_ips -= 2; // Exclude network ID and limited broadcast ID

    // Calculate limited broadcast ID
    unsigned int broadcast_id[4];
    for (int i = 0; i < 4; i++) {
        broadcast_id[i] = network_id[i] | (~subnet_mask[i] & 255);
    }

    // Print results
    printf("Network ID: %u.%u.%u.%u\n", network_id[0], network_id[1], network_id[2], network_id[3]);
    printf("Subnet Mask: %u.%u.%u.%u\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Total number of IP addresses: %u\n", total_ips);
    printf("Limited Broadcast ID: %u.%u.%u.%u\n", broadcast_id[0], broadcast_id[1], broadcast_id[2], broadcast_id[3]);
}

int main() {
    char ip_address[20];
    printf("Enter the IP address (format: x.x.x.x): ");
    scanf("%s", ip_address);

    calculate(ip_address);

    return 0;
}
