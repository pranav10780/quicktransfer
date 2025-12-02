#include <stdio.h>
#include <stdlib.h>

int ip_addr_finding(){
	//trying to ping all device in subnet
	//ip -o -4 addr show scope global | awk '{print $4}' | wc -l  too show only ip address of interfaces with mask attached
	//TODO: replace the above command with acutal func to check all ip addresses
	FILE *f;
	char number[64];
	char ips[atoi(number)][16];

	f = popen("ip -o -4 addr show scope global | awk '{print $4}' | grep \"/24\" | wc -l","r");
	if (!f){
		perror("command not working for finding ips");
		return -1;
	}

	//checking if variable number is empty
	if (fgets(number,sizeof(number),f) == NULL){
		perror("failed to get ips");
		return -1;
	}

	//closing the pipe opened by *f
	pclose(f);



	//TODO: only currently working wiht /24 networks need to work on that
	f = popen("ip -o -4 addr show scope global | awk '{print $4}' | grep \"/24\" | cut -d/ -f1","r");
	if (!f){
		perror("command not working for finding ips");
		return -1;
	}


	//testing
	char temp[50];
	fgets(temp,sizeof(temp),f);
	printf("%s\n",temp);
	pclose(f);
	
	//convert ascii to integer
	return atoi(number);
}

int main(){
	int numberofip = ip_addr_finding();
	printf("no of ips:%d\n",numberofip);
	return 0;
}
