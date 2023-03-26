//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include<TlHelp32.h>
#include "ShObjIdl.h"
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <tchar.h> // _tcscmp
#include <array>
#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
#include <Windows.h>
#include "memory.h"
#include <random>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
//---------------------------------------------------------------------------
USEFORM("main.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
