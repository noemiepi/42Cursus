<div align="center">
	<h1>Born2beRoot</h1>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
	- [Project overview](#project-overview)
	- [Simple setup](#simple-setup)
	- [User](#user)
	- [Hostname and partitions](#hostname-and-partitions)
	- [SUDO (Super User DO)](#sudo-super-user-do)
	- [UFW (Uncomplicated Firewall)](#ufw-uncomplicated-firewall)
	- [SSH (Secure SHell)](#ssh-secure-shell)
	- [Script monitoring](#script-monitoring)
- [Bonus](#bonus)
- [Throughout comparisons](#throughout-comparisons)
	- [Debian vs Rocky Linux](#debian-vs-rocky-linux)
	- [AppArmor vs SELinux](#apparmor-vs-selinux)
	- [UFW vs firewalld](#ufw-vs-firewalld)
	- [VirtualBox vs UTM](#virtualbox-vs-utm)
- [Resources](#resources)

## Description
The goal of this project is to set up our first server by following specific rules. For this, we will create a virtual machine (VM) on which we will set it up.

## Instructions
For the verifications, tests and questions of the Virtual Machine for the evaluation will be in the following part.

### Project overview
To check the signature:
```bash
shasum machinename.vdi
```

#### A Virtual Machine (VM)
**What is it?**
- It simulates a computer.

**What are the advantages?**
- No matter what happens inside the VM, it stays inside it.
- It can be used to test viruses or anti-viruses without damaging the physical computer.

#### The Operating System (OS) Choice
A few parameters must be looked at when choosing an Operating System, such as:
- *The stability:* If it is not changing, one or a few new major versions.
- *The community:* It will help regarding the documentation or correctly setting up the OS.
- *The scale:* If this will be for desktop use or for servers.

#### Differences between Debian and Rocky Linux
**Debian**
- It is a recommended OS for beginners in system administration.
- It is a stable OS.
- There is a lot of documentation and a big community.
- Use `apt` and `.deb` files.

- Despite those advantages, a prior knowledge of Linux is needed to use it comfortably.

**Rocky Linux**
- It is focused on enterprises and integrates hyper-scale, cloud and high-performance computing.
- It's also a stable operating system that functions reliably.

- It's not the best choice for desktop use as it's mainly meant for servers.

It's for those reasons and the fact that I have no prior knowledge in system administration that, for this project, I used Debian instead of Rocky Linux.

#### Apt vs Aptitude and APPArmor
**Apt**
- It offers a command-line interface.
- It will not fix the issue if it comes across a package conflict.

**Aptitude**
- It offers a visual interface.
- It will suggest a resolution if faced with a package conflict.

**AppArmor**
- It offers a simple, path-based approach to security and is easy to configure making it ideal for desktops or servers where ease of management is the priority.
- It is an alternative to SELinux.

### Simple setup
To check the graphic interface:
```bash
ls /usr/bin/*session
```

To check if the UFW service has started:
```bash
sudo ufw status
```
```bash
sudo service ufw status
```

To check if the SSH service has started:
```bash
sudo service ssh status
```

To check the chosen OS:
```bash
uname -a
```
OS name, host session name, and other things
or
```bash
uname --kernel-version
```
Only the OS name.

### User
To check the existing group(s):
```bash
getent group sudo
getent group user42
```

To add a user and apply the password policy:
```bash
sudo adduser <son_login>
```

**How have the rules been set up?**
- `nano /etc/login.defs`
- `nano /etc/security/pwquality.conf`
or
- `nano /etc/pam.d/common-password`
(it depends on which file was modified during the configuration)

To add a new group:
```bash
sudo addgroup <nom>
```

To add the user to a group:
```bash
sudo adduser name_user evaluating
```

To check the new user's group(s):
```bash
groups name_user
```

**What are the advantages of the password policy?**
(same as underneath)

**What are the advantages and disadvantages of its implementation?**
- *Advantages*
	- A long and complex password reduces the risks of having a compromised password.
	- Makes users unable to use overly simple password such as `12345`, `password` or `root`.
	- It protects the root account.
- *Disadvantages*
	- The possibility to forget the password is higher.
	- Nothing prevents the user to write it somewhere obvious (their desk) or from being hacked.

### Hostname and partitions
To check the hostname:
```bash
hostname
```

To change the hostname:
```bash
sudo nano /etc/hostname
```
and
```bash
sudo nano /etc/hosts
```
```bash
sudo reboot
```
```bash
hostname
```

To check the partitions:
```bash
lsblk
```

**How does LVM (Logical Volume Manager) work and what is it about?**
It is a system that enables the user to create logical volumes and use multiple files system on one or multiple disks.<br>
It has 3 different layers:
- *Physical Volumes*: it corresponds with either physical disks or the partitions on them.
- *Volume Groups*: it groups multiple physical disks or partitions together.
- *Logical Volumes*: it is where we create files and stock data.

### SUDO (Super User DO)
To check sudo:
```bash
which sudo
```

To add a sudo:
```bash
sudo adduser <login> sudo
```
```bash
getent group sudo
```

**What is SUDO and what is its value?**
- It grants a user the authorization to execute a command as another user (by default it is the root, so the administrator).

To check the sudo policy:
```bash
sudo visudo
```

To check the sudo log:
```bash
cd /var/log/sudo
```
Shows that there is at least one file present.
```bash
ls
```
```bash
cat sudo.log
```

### UFW (Uncomplicated Firewall)
To check the UFW:
```bash
sudo service ufw status
```
```bash
sudo ufw status numbered
```

**What is a UFW and what is its value?**
- It is a firewall.
- It protects the different ports by defining the allowed and blocked connexions.

To add a new rule:
```bash
sudo ufw allow 8080
```
```bash
sudo ufw status numbered
```

To delete a rule:
```bash
sudo ufw delete <num_rule>
```
```bash
sudo ufw status numbered
```

### SSH (Secure SHell)
**What is a SSH and what is its value?**
- It is a method to securely send commands to a computer over an unsecured network.
- It enables us to securely connect ourselves at a distance thanks to a SHELL terminal.
- The communication is ciphered.

To check SSH:
```bash
which ssh
```
```bash
sudo service ssh status
```

### Script monitoring
To open Crontab:
```bash
sudo crontab -u root -e
```
This line appears in the file.
```bash
*/10 * * * * /home/npillet/monitoring.sh
```
This makes the script run every 10 minutes.

To see the script:
```bash
cd /home/npillet
```
```bash
nano monitoring.sh
```

**How does the script, `monitoring.sh`, work?**
- `grep`: to search a specific term, between " ". -v is to exclude a term between " ".
- `wc`: word count, -l is for lines, -w is for words.
- `awk`: it is a list of actions.
- `top`: it provides a dynamic real-time view of a running system.
- `cut`: to remove sections from each line of files.
- `ss`: to dump socket statistics. It shows similar informations to netstat. -ta flag is to only show TCP connections.
- `journalctl`: it collects and manages the system logs.

To change the time between each script apparition:
```bash
sudo crontab -u root -e
```
```bash
*/1 * * * * /home/npillet/monitoring.sh
```
This will make the script run every minute.

To stop the script:
```bash
sudo crontab -u root -e
```
Remove the line(s):
```bash
@reboot /home/monitoring.sh
*/1 * * * * /home/npillet/monitoring.sh
```

To verify the changes:
```bash
sudo reboot
```
Check the file is in the same place.
```bash
cd /home/npillet
```
```bash
ls
```
The permissions.
```bash
ls -ld monitoring.sh
```
Check the file hasn't been modified.
```bash
nano monitoring.sh
```

**What is "cron"?**
- It is a service executing defined tasks at chosen moments.

## Bonus
The partitioning and the WordPress were done for the bonus.
To see the WordPress, open a browser page and type:
```bash
https://127.0.0.1:1672
```
127.0.0.1 is the post host.

1672 is the host port that was assigned to the site.

## Throughout comparisons
### Debian vs Rocky Linux
Debian is a recommended operating system for beginners in system administration, it's completely free, excellent web site and community resources, well-tested, painless software installation with apt-get.<br>
Despite those advantages, a prior knowledge of Linux is needed to use it comfortably,not every hardware is supported and the time between releases of stable versions is long.


Rocky Linux is focused on enterprises and integrates hyper-scale, cloud and high-performance computing. It's also a stable operating system that functions reliably.<br>
But this operating system is mainly meant for servers and only in a limited way for desktop use; therefore, it's not the best choice for desktop use.

### AppArmor vs SELinux
AppArmor offers a simpler, path-based approach to security and is easier to configure, making it ideal for desktops or servers where ease of management is the priority.


Whereas SELinux offers a more granular, label-based control for enhanced security.<br>
SELinux is more adapted for enterprise and high-security environments as it offers stricter security with fine-grained, mandatory access controls.


Both of them introduce some performance overhead.

### UFW vs firewalld
UFW is really simple to set up and manage and can define application profiles for common services. But it has limited advanced features, such as no email alerts or login tracking, and it's not ideal for complex multi-server environments, making it more suited for Debian.


For firewalld, it has dynamic rule changes, an integration with NetworkManager and systemd and granular control via zones.Whoever, it has a slightly more complex for beginners and not as user-friendly as UFW.

### VirtualBox vs UTM
VirtualBox is free and open-source. It supports a wide range of Linux distributions (distros) and is feature-rich.


UTM, on the other hand, is a macOS-specific VM. It's lightweight and uses fewer computer resources compared to VirtualBox. It doesn't support as many Linux distros or advanced features; it lacks graphics virtualization.

## Resources
### Notions
#### Guides for the VM setup
- [chlimous](https://github.com/chlimous/42-born2beroot_guide?tab=readme-ov-file)

- [alizealebaron](https://github.com/alizealebaron/Born2beroot)

- [mcombeau](https://github.com/mcombeau/Born2beroot/blob/main/guide/configuration_debian.md)

- [gemartin99](https://noreply.gitbook.io/born2beroot/installing-the-virtual-machine/virtual-machine-iso)

#### Guide for the script
- [Script](https://noreply.gitbook.io/born2beroot/virtual-machine-setup/script)

#### Informations
- [Debian](https://truxgoservers.com/blog/advantages-and-disadvantages-of-using-debian/)

- [Rocky Linux](https://forums.rockylinux.org/t/what-are-your-thoughts-on-using-rocky-linux-as-the-operating-system-for-servers-and-desktop-computers/10839)

- [APT vs Aptitude](https://blog.packagecloud.io/know-the-difference-between-apt-and-aptitude/)

- [LVM](https://www.informatiweb-pro.net/admin-systeme/linux/installer-et-utiliser-le-lvm-sous-linux.html)

- [SELinux vs APPArmor](https://tuxcare.com/blog/selinux-vs-apparmor/)

- [UFW vs Firewalld](https://blog.hosteons.com/2025/10/21/best-firewalls-for-linux-vps-ufw-vs-csf-vs-firewalld/)

- [SSH](https://www.cloudflare.com/learning/access-management/what-is-ssh/)

- [VirtualBox vs UTM](https://www.howtogeek.com/virtualbox-vs-utm-which-is-best-for-linux-vms-on-mac/)

<br>
<hr>
<br>

<div align="center">
    <img src="assets/footer.png" />
</div>
