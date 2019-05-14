// AXNET.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include <iostream>
#include<winsock2.h>

#include "AXSMWL.h"
#include "AXGL.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define BUFLEN 729  //Max length of buffer
#define PORT 4950   //The port on which to listen for incoming data
#define SERVER "192.168.1.103"  //ip address of udp server



int main()
{
	std::cout << "AXNETW V0.3 C++ "<<std::endl;

	while (1){
		struct sockaddr_in si_otherD;
		int sD, slenD = sizeof(si_otherD);
		char bufD[BUFLEN];
		char messageD[BUFLEN];
		WSADATA wsaD;

		//Initialise winsock
	//	printf("\nInitialising Winsock...");
		if (WSAStartup(MAKEWORD(2, 2), &wsaD) != 0)
		{
			printf("Failed. Error Code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		//printf("Initialised.\n");

		//create socket
		if ((sD = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
		{
			printf("socket() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		//setup address structure
		memset((char *)&si_otherD, 0, sizeof(si_otherD));
		si_otherD.sin_family = AF_INET;
		si_otherD.sin_port = htons(PORT);
		si_otherD.sin_addr.S_un.S_addr = inet_addr(SERVER);

		//start communication
		//while (1)
		//{
		memset(messageD, '\0', 729);
	printf("AXCOMAND: ");
		gets(messageD);
		
		//strncpy(messageD, "Y1123 X765", 729);

		//send the message
		if (sendto(sD, messageD, strlen(messageD), 0, (struct sockaddr *) &si_otherD, slenD) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d", WSAGetLastError());
			//exit(EXIT_FAILURE);
		}
		std::cout << "AXI:" << messageD << std::endl;
		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
	//	memset(bufD, '\0', BUFLEN);
		//try to receive some data, this is a blocking call
		/*if (recvfrom(sD, bufD, BUFLEN, 0, (struct sockaddr *) &si_otherD, &slenD) == SOCKET_ERROR)
		{
		printf("recvfrom() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
		}

		puts(bufD);
		}*/

		closesocket(sD);
		WSACleanup();





		SOCKET s;
		struct sockaddr_in server, si_other;
		int slen, recv_len;
		char buf[BUFLEN];
		char data[729];
		WSADATA wsa;

		slen = sizeof(si_other);

		//Initialise winsock
		//printf("\nInitialising Winsock...");
		if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		{
			printf("Failed. Error Code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}
	//	printf("Initialised.\n");

		//Create a socket
		if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
		{
		//	printf("Could not create socket : %d", WSAGetLastError());
		}
		//printf("Socket created.\n");

		//Prepare the sockaddr_in structure
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_port = htons(PORT);

		//Bind
		if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
		{
			printf("Bind failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		//puts("Bind done");

		//keep listening for data
		
			//printf("Waiting for data...");
			fflush(stdout);

			//clear the buffer by filling null, it might have previously received data
			memset(buf, '\0', BUFLEN);


			int nTimeout = 1000; // 1 seconds
			setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (const char*)&nTimeout, sizeof(int));

			//try to receive some data, this is a blocking call
			if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == WSAETIMEDOUT)
			{
				//printf("recvfrom() failed with error code : %d", WSAGetLastError());
				//exit(EXIT_FAILURE);
			}
			else{

				//print details of the client/peer and the data received
				//printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
				//printf("Data: %s\n", buf);
			
				strncpy(data,buf,729);
			}
			std::cout << "AXD:" << data<<std::endl;
			//printf("Data: %s\n",data);
			//now reply the client with the same data
		/*	if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
			{
				printf("sendto() failed with error code : %d", WSAGetLastError());
				exit(EXIT_FAILURE);
			}*/
		

		closesocket(s);
		WSACleanup();
	}
	
	return 0;
}
