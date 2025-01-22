# Computer Network Lab Assignment 1

## Network Tools and Socket Programming

### a. ifconfig
```bash
ifconfig eth0 up
```
- _Network Configuration:_ ifconfig allows users to configure network interfaces, including setting IP addresses, netmasks, and broadcast addresses.
- _Network Troubleshooting:_ It provides detailed information about network interfaces, which is essential for diagnosing connectivity issues, monitoring network traffic, and checking interface statuses.

### b. traceroute
```bash
traceroute google.com
```
The `traceroute` command is a network diagnostic tool used to trace the route taken by packets from a source to a destination over an IP network.

### c. ping
```bash
ping 8.8.8.8
```
The `ping` command is a powerful tool that allows users to check the status of their internet connection and diagnose network-related issues. The PING (Packet Internet Groper) command is used to check the network connectivity between the host and server/host.

### d. dig 
```bash
dig example.com
```
`dig` retrieves information about DNS name servers. Network administrators use it to verify and troubleshoot DNS problems and perform DNS lookups. The dignslookup and the host.

### e. telnet
```bash
telnet mail.example.com 25
```
We can use the `telnet` command to connect to a port on a remote server to verify if the path from our computer to that server is open over that port.

### f. nslookup
```bash
nslookup example.com
```
`nslookup` (stands for “Name Server Lookup”) is a useful command for getting information from the DNS server. It is a network administration tool for querying the Domain Name System (DNS) to obtain domain name or IP address mapping or any other specific DNS record. It is also used to troubleshoot DNS-related problems.

### g. netstat
```bash
netstat -an
```
`netstat` stands for network statistics. It allows users to display network-related information and diagnose various networking issues. The command has several options that can be combined to retrieve specific details. 

### h. scp 
```bash
scp file.txt user@remote:/path/to/destination
```
`scp` (secure copy) command in Linux system is used to copy file(s) between servers in a secure way. The SCP command or secure copy allows the secure transferring of files between the local host and the remote host or between two remote hosts.

### i. w 
```bash
man w
```
The `w` command in Linux gives us important information about who is currently using the computer, how much the computer is being used, and what programs are running.

### j. nmap
```bash
nmap -sS 192.168.1.1
```
`nmap` is Linux command-line tool for network exploration and security auditing. This tool is generally used by hackers and cybersecurity enthusiasts and even by network and system administrators. It is used for the following purposes: 

- Real time information of a network
- Detailed information of all the IPs activated on your network
- Number of ports open in a network
- Provide the list of live hosts
- Port, OS and Host scanning

### k. ifup/ ifdown
```bash
ifup eth0
```
The `ifup` command in Linux is essential for managing network interfaces, allowing them to transmit and receive data by bringing them up.
```bash
ifdown eth0
```
`ifdown` is used to bring network interfaces down, essentially disabling them so they cannot transmit or receive data. 

_Unlike the `ifup` command, which activates the network interface, `ifdown` places the interface in a non-operational state, preventing it from handling network traffic._ 

### l. route
```bash
route add default gw 192.168.1.1
```
The IP/kernel routing table acts as a crucial map, determining how network packets are forwarded between different hosts and networks.

### m. host
```bash
host example.com
```
`host` command is used to find the IP address of a particular domain name or if you want to find out the domain name of a particular IP address the host command becomes handy. 

### n. arp
```bash
arp -a
```
`arp` command manipulates the System’s ARP cache. It also allows a complete dump of the ARP cache. ARP stands for Address Resolution Protocol. The primary function of this protocol is to resolve the IP address of a system to its mac address.

### o. ethtool
```bash
ethtool eth0
```
The `ethtool` command in Linux is used to display and change the settings of your network interface card (NIC). 

### p. iwconfig
```bash
iwconfig wlan0 essid "NetworkName"
```
The `iwconfig` command is part of the wireless-tools package in Linux and is used to configure and display information about wireless network interfaces. It provides a convenient way to view and modify wireless interface settings, such as network name (SSID), encryption keys, and transmission power.

### q. system-config-network
```bash
system-config-network
```
`system-config-network` allows users to set up network interfaces, manage DNS settings, and configure other network-related parameters via an interactive graphical interface or a text-based interface.

### r. bmon
```bash
man bmon
```
`bmon` stands is an open source tool for the bandwidth monitoring tool. `bmon` is a powerful CLI based network bandwidth monitoring and debugging tool for Unix / Linux systems to capture networking related statistics & present them visually on the command line in a human-friendly way.

### s. ssh
```bash
ssh [username]@[hostname or IP address]
```
`ssh` or Secure Shell, constitutes a cryptographic network protocol designed to enable secure communication between two systems over networks that may not be secure. This protocol is widely employed for remote access to servers and the secure transmission of files between computers.

### t. tcpdump
```bash
tcpdump -i eth0
```
`tcpdump` is a packet sniffing and packet analyzing tool for a System Administrator to troubleshoot connectivity issues in Linux.

### u. dstat
```bash
dstat
```
`dstat` is a tool that is used to retrieve information or statistics form components of the system such as network connections, IO devices, or CPU, etc. It is generally used by system administrators to retrieve a handful of information about the above-mentioned components of the system.

### v. dhclient
```bash
dhclient eth0
```
`dhclient` is a target utility. The Internet Software Consortium DHCP client, dhclient , provides a means for configuring one or more network interfaces using the Dynamic Host Configuration Protocol.

### w. nload
```bash
nload
```
`nload` is a console-based application which monitors network traffic and bandwidth usage in real. It provides information about incoming and outgoing traffic using graphs, and additionally it provides information like current data transferring rate average data transferred, and minimum and maximum data transferred by the network.

### x. iftop
```bash
iftop -i eth0
```
`iftop` provides a quick and detailed overview of networking activities, helping diagnose network issues by identifying which applications or processes are consuming the most bandwidth.

### y. ip
```bash
ip addr
```
The `ip` command in Linux is a powerful utility for network configuration and management. It allows users to interact with various networking components such as network interfaces, routing tables, addresses, and more.

### z. iptables
```bash
iptables -A INPUT -p tcp --dport 22 -j ACCEPT
```
On using this `iptables` you can set up security policies to control incoming and outgoing traffic, define port forwarding, and implement network address translation (NAT).

### aa. sftp
```bash
sftp user@remote_host
```
`sftp` stands for Secure File Transfer Protocol. It is a secure and efficient method for transferring files in the Linux environment.

### bb. socat
```bash
socat TCP4-LISTEN:1234,fork EXEC:/bin/bash
```
`socat` (for SOcket CAT) establishes two bidirectional byte streams and transfers data between them. Data channels may be files, pipes, devices (terminal or modem, etc.), or sockets (Unix, IPv4, IPv6, raw, UDP, TCP, SSL).

### cc. rsync
```bash
rsync -avz /src/ user@remote:/dest/
```
`rsync` or remote synchronization is a software utility for Unix-Like systems that efficiently sync files and directories between two hosts or machines.

### dd. wget
```bash
wget https://example.com/file.zip
```
`wget` is the non-interactive network downloader which is used to download files from the server even when the user has not logged on to the system and it can work in the background without hindering the current process.

### ee. curl
```bash
curl -O https://example.com/file.zip
```
`curl` supports a wide range of protocols, making it an invaluable tool for fetching, uploading, and managing data over the Internet.


## a. Stream Socket

> server.cpp

```bash
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(new_socket, buffer, 1024);
    std::cout << "Message from client: " << buffer << std::endl;

    send(new_socket, "Hello from server", 17, 0);
    close(new_socket);
    return 0;
}
```
> client.cpp

```bash
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    send(sock, "Hello from client", 17, 0);
    read(sock, buffer, 1024);
    std::cout << "Message from server: " << buffer << std::endl;

    close(sock);
    return 0;
}
```
## b. Datagram Socket

> server.cpp

```bash
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    socklen_t len = sizeof(cliaddr);
    recvfrom(sockfd, buffer, 1024, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
    std::cout << "Message from client: " << buffer << std::endl;

    sendto(sockfd, "Hello from server", 17, MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
    return 0;
}
```
> client.cpp

```bash
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    sendto(sockfd, "Hello from client", 17, MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    socklen_t len = sizeof(servaddr);
    recvfrom(sockfd, buffer, 1024, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
    std::cout << "Message from server: " << buffer << std::endl;

    return 0;
}
```

## c. Raw socket
> raw.cpp
```bash
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>

unsigned short checksum(void *b, int len) {
    unsigned short *buf = (unsigned short *)b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in dest_addr;
    struct icmp icmp_header;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr("8.8.8.8"); // Replace with the destination IP

    icmp_header.icmp_type = ICMP_ECHO;
    icmp_header.icmp_code = 0;
    icmp_header.icmp_cksum = 0;
    icmp_header.icmp_id = getpid();
    icmp_header.icmp_seq = 1;

    icmp_header.icmp_cksum = checksum(&icmp_header, sizeof(icmp_header));

    if (sendto(sockfd, &icmp_header, sizeof(icmp_header), 0,
               (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("Failed to send packet");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    std::cout << "ICMP Echo Request sent to 8.8.8.8" << std::endl;

    socklen_t addr_len = sizeof(dest_addr);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0,
                 (struct sockaddr *)&dest_addr, &addr_len) < 0) {
        perror("Failed to receive packet");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    std::cout << "ICMP Echo Reply received from 8.8.8.8" << std::endl;

    close(sockfd);
    return 0;
}
```
