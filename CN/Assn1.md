
# Computer Network Lab Assignment 1

## Network Tools and Socket Programming

### a. ifconfig
```bash
man ifconfig
```
- _Network Configuration:_ ifconfig allows users to configure network interfaces, including setting IP addresses, netmasks, and broadcast addresses.
- _Network Troubleshooting:_ It provides detailed information about network interfaces, which is essential for diagnosing connectivity issues, monitoring network traffic, and checking interface statuses.

### b. traceroute
```bash
man traceroute
```
The `traceroute` command is a network diagnostic tool used to trace the route taken by packets from a source to a destination over an IP network.

### c. ping
```bash
man ping
```
The `ping` command is a powerful tool that allows users to check the status of their internet connection and diagnose network-related issues. The PING (Packet Internet Groper) command is used to check the network connectivity between the host and server/host.

### d. dig 
```bash
man dig
```
`dig` retrieves information about DNS name servers. Network administrators use it to verify and troubleshoot DNS problems and perform DNS lookups. The dignslookup and the host.

### e. telnet
```bash
man telnet
```
We can use the `telnet` command to connect to a port on a remote server to verify if the path from our computer to that server is open over that port.

### f. nslookup
```bash
man nslookup
```
`nslookup` (stands for “Name Server Lookup”) is a useful command for getting information from the DNS server. It is a network administration tool for querying the Domain Name System (DNS) to obtain domain name or IP address mapping or any other specific DNS record. It is also used to troubleshoot DNS-related problems.

### g. netstat
```bash
man netstat
```
`netstat` stands for network statistics. It allows users to display network-related information and diagnose various networking issues. The command has several options that can be combined to retrieve specific details. 

### h. scp 
```bash
man scp
```
`scp` (secure copy) command in Linux system is used to copy file(s) between servers in a secure way. The SCP command or secure copy allows the secure transferring of files between the local host and the remote host or between two remote hosts.

### i. w 
```bash
man w
```
The `w` command in Linux gives us important information about who is currently using the computer, how much the computer is being used, and what programs are running.

### j. nmap
```bash
man nmap
```
`nmap` is Linux command-line tool for network exploration and security auditing. This tool is generally used by hackers and cybersecurity enthusiasts and even by network and system administrators. It is used for the following purposes: 

- Real time information of a network
- Detailed information of all the IPs activated on your network
- Number of ports open in a network
- Provide the list of live hosts
- Port, OS and Host scanning

### k. ifup/ ifdown
```bash
man ifup
```
The `ifup` command in Linux is essential for managing network interfaces, allowing them to transmit and receive data by bringing them up.
```bash
man ifdown 
```
`ifdown` is used to bring network interfaces down, essentially disabling them so they cannot transmit or receive data. 

_Unlike the `ifup` command, which activates the network interface, `ifdown` places the interface in a non-operational state, preventing it from handling network traffic._ 

### l. route
```bash
man route
```
The IP/kernel routing table acts as a crucial map, determining how network packets are forwarded between different hosts and networks.

### m. host
```bash
man host
```
`host` command is used to find the IP address of a particular domain name or if you want to find out the domain name of a particular IP address the host command becomes handy. 

### n. arp
```bash
man arp
```
`arp` command manipulates the System’s ARP cache. It also allows a complete dump of the ARP cache. ARP stands for Address Resolution Protocol. The primary function of this protocol is to resolve the IP address of a system to its mac address.

### o. ethtool
```bash
man ethtool
```
The `ethtool` command in Linux is used to display and change the settings of your network interface card (NIC). 

### m. iwconfig
```bash
man iwconfig
```
The `iwconfig` command is part of the wireless-tools package in Linux and is used to configure and display information about wireless network interfaces. It provides a convenient way to view and modify wireless interface settings, such as network name (SSID), encryption keys, and transmission power.
