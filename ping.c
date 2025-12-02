#include <stdio.h>
#include <stdlib.h>

int ip_addr_finding(){
	//trying to ping all device in subnet
	//ip -o -4 addr show scope global | awk '{print $4}' | wc -l  too show only ip address of interfaces with mask attached
	FILE *f = ("ip -o -4 addr show scope global | awk '{print $4}' | wc -l","r");
	if (!f){
		perror("command not working for finding ips");
		return -1;
	}

	//saving output to variable number
	char number[64];
	//checking if variable number is empty
	if (fgets(number,sizeof(number),f) == NULL){
		perror("No output recieved from command");
		return -1;
	}

	//closing the pipe opened by *f
	pclose(f);
	
	//convert ascii to integer
	return atoi(number);
}

int main(){
	int numberofip = ip_addr_finding();
	printf("%d\n",numberofip);
	return 0;
}
