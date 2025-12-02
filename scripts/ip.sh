#!/bin/bash

#ip.sh
#instead of relying on nmap for scaning all active devices on the subnet
#we will use bash script cause y not
#made by pranv10780

echo "Starting to scan the subnet"
sleep .2
echo "Identifying network broadcast address"

#actual command which gives us ip addr as a string seperated by space
ips="$(hostname -I)"
#ip_addr is the list which contains the ip address
read -ra ip_addr <<< "$ips"

#looping and checking every single active pc in the network
for ip in "${ip_addr[@]}"; do
	for ((j=0; j<255; j++)); do
		ping -c 1 -W 1 ${ip_addr[i]%.*}.$j > /dev/null 2>&1 && echo "Found:${ip_addr[i]%.*}.$j"
	done
done
#TODO
make cntrl c logic cancel all commands
make search faster
make a progress bar if possible

exit 0
