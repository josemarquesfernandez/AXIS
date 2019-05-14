#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#include <iostream> 
#include <atlbase.h>
#include <atlconv.h>



#define BUF_SIZE 729
TCHAR szName[] = TEXT("AXDATA");
TCHAR szMsg[] = TEXT("WIIII NDOWS SHARED");

HANDLE hMapFile;
LPCTSTR pBuf;

	int ISMDW(){
		hMapFile = CreateFileMapping(
			INVALID_HANDLE_VALUE,    // use paging file
			NULL,                    // default security
			PAGE_READWRITE,          // read/write access
			0,                       // maximum object size (high-order DWORD)
			BUF_SIZE,                // maximum object size (low-order DWORD)
			szName);                 // name of mapping object

		if (hMapFile == NULL)
		{
			_tprintf(TEXT("Could not create file mapping object (%d).\n"),
				GetLastError());
			return 1;
		}
		pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
			FILE_MAP_ALL_ACCESS, // read/write permission
			0,
			0,
			BUF_SIZE);

		if (pBuf == NULL)
		{
			_tprintf(TEXT("Could not map view of file (%d).\n"),
				GetLastError());

			CloseHandle(hMapFile);

			return 1;
		}
	}

	void WSMD( TCHAR* in){
		szMsg[] = in[];
		CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
		_getch();
	}

	void CSMDW(){ UnmapViewOfFile(pBuf); }

	//HANDLE hMapFile;
	//LPCTSTR pBuf;
	int ISMDR(){
		hMapFile = OpenFileMapping(
			FILE_MAP_ALL_ACCESS,   // read/write access
			FALSE,                 // do not inherit the name
			szName);               // name of mapping object

		if (hMapFile == NULL)
		{
			_tprintf(TEXT("Could not open file mapping object (%d).\n"),
				GetLastError());
			return 1;
		}
	}

	char *RSMD(){
		pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
			FILE_MAP_ALL_ACCESS,  // read/write permission
			0,
			0,
			BUF_SIZE);

		if (pBuf == NULL)
		{
			_tprintf(TEXT("Could not map view of file (%d).\n"),
				GetLastError());

			CloseHandle(hMapFile);

			//return 1;
		}

		//MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
		CT2A ch(pBuf);
		std::cout << ch;
		return ch;
	}
	
	void CSMDR(){
		UnmapViewOfFile(pBuf);

		CloseHandle(hMapFile);
	}


