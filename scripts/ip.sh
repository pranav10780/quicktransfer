#!/bin/bash

# ip.sh
# instead of relying on nmap for scaning all active devices on the subnet
# we will use bash script cause y not
# made by pranv10780

echo "Starting to scan the subnet"
sleep .2
echo "Identifying network broadcast address"
# for actually making the file not have old data
> ip_addr.txt

# actual command which gives us ip addr as a string seperated by space
ips="$(hostname -I)"
# ip_addr is the list which contains the ip address
read -ra ip_addr <<< "$ips"

for ip in "${ip_addr[@]}"; do
  # get the subnet prefix (strip last octet)
  prefix="${ip%.*}"

  # optional subnet debuging code below
  # echo "Scanning subnet ${prefix}.0/24"

  for j in {1..254}; do
    target="$prefix.$j"
    if ping -c 1 -W 1 "$target" >/dev/null 2>&1; then
      echo "$target" >> ip_addr.txt
    fi
  done
done

# TODO
# make cntrl c logic cancel all commands
# make search faster
# make a progress bar if possible
# save ips to file
echo "Program finished"
exit 0
