#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpup=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpuv=$(grep processor /proc/cpuinfo | wc -l)

# RAM
uram=$(free --mega | awk '$1 == "Mem:" {print $3}')
tram=$(free --mega | awk '$1 == "Mem:" {print $2}')
pram=$(free --mega | awk '$1 == "Mem:" {printf("(%.2f)\n", $3/$2*100)}')

# DISK
udisk=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} END {print use}')
tdisk=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{tot += $2} END {printf ("%.1fGb\n"), tot/1024}')
pdisk=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {tot += $2} END {printf("%d"), use/tot*100}')

# CPU LOAD
cpul=$(top -bn1 | grep "Cpu" | cut -d ' ' -f 3)

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if [$(lsblk | grep "lvm" | wc -l) -gt 0]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
tcp=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "
-------------------------------------------------
Architecture	: $arch
CPU physical	: $cpup
vCPU		: $cpuv
Memory usage	: $uram/${tram}MB ($pram%)
Disk usage	: $udisk/${tdisk} ($pdisk%)
CPU load	: $cpul%
Last boot	: $lb
LVM use		: $lvmu
Connections TCP : $tcp ESTABLISHED
User log	: $ulog
Network		: IP $ip ($mac)
Sudo		: $cmnd cmd
-------------------------------------------------"
