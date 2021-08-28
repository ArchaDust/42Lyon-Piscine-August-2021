ifconfig -a link | grep ether | cut -c 8- | tr -d ' '
