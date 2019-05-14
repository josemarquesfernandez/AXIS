// AXCOM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>

// application reads from the specified serial port and reports the collected data
int _tmain(int argc, _TCHAR* argv[])
{
	std::cout<< "AXCOM V0.3 C++" << std::endl;

	Serial* SP = new Serial("\\\\.\\COM24");    // adjust as needed

	

	if (SP->IsConnected())
		std::cout << "LINK" << std::endl;

	char Data[11] = "";
	char Inst[11] = "S0.0 \n\n\0\0\0";	// don't forget to pre-allocate memory
	//printf("%s\n",incomingData);
	int dataLength = 11;
	int instLength = 11;
	int readResult = 0;
	int writeResult = 0;

	while (SP->IsConnected())
	{
		writeResult = SP->WriteData(Inst, instLength);
		std::cout << "AXI: " <<Inst<< std::endl;
		//printf("AXI: (-1 means no data available) %i\n", writeResult);
		//printf("%s", Inst);

		readResult = SP->ReadData(Data, dataLength);
		std::cout << "AXD: " << Data << std::endl;
		//printf("AXD: (-1 means no data available) %i\n", readResult);
		//printf("%s", Data);

		
		//Sleep(500);
	}
	return 0;
}



