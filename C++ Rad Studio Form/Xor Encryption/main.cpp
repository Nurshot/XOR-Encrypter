//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
std::string XOR_Encryption(std::string toBeEncrypted, std::string sKey)
{
	std::string sEncrypted(toBeEncrypted);
	unsigned int iKey(sKey.length()), iIn(toBeEncrypted.length()), x(0);
	for (unsigned int i = 0; i < iIn; i++)
	{
		sEncrypted[i] = toBeEncrypted[i] ^ sKey[x];
		if (++x == iKey) { x = 0; }
	}
	return sEncrypted;
}


void hex2stream(const string hexstr, std::string& str)
{
	str.resize((hexstr.size() + 1) / 2);

	for (size_t i = 0, j = 0; i < str.size(); i++, j++)
	{
		str[i] = (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) << 4, j++;
		str[i] |= (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) & 0xF;
	}
}


void stream2hex(const string str, std::string& hexstr, bool capital = false)
{
	hexstr.resize(str.size() * 2);
	const size_t a = capital ? 'A' - 1 : 'a' - 1;

	for (size_t i = 0, c = str[0] & 0xFF; i < hexstr.size(); c = str[i / 2] & 0xFF)
	{
		hexstr[i++] = c > 0x9F ? (c / 16 - 9) | a : c / 16 | '0';
		hexstr[i++] = (c & 0xF) > 9 ? (c % 16 - 9) | a : c % 16 | '0';
	}
}


//----------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    std::string key1 = "u8skjnandkrem=)^!.<pS>(=_=)";
	AnsiString text= Form1->Edit1->Text;

    std::string e1 = XOR_Encryption(text.c_str(), key1);
	stream2hex(e1, e1, true);
	Edit2->Text=e1.c_str();





	hex2stream(e1, e1);
	std::string d1 = XOR_Encryption(e1, key1);
	Edit3->Text=d1.c_str();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    std::string key1 = "u8skjnandkrem=)^!.<pS>(=_=)";
	AnsiString text= Form1->Edit1->Text;
	std::string ad=text.c_str();
	hex2stream(ad, ad);
	std::string d1 = XOR_Encryption(ad, key1);
	//Edit2->Text=ad.c_str();
    Edit3->Text=d1.c_str();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if(Form1->CheckBox1->Checked){
		Form1->FormStyle = fsStayOnTop;

	}
	else{
		Form1->FormStyle = fsNormal;
	}
}
//---------------------------------------------------------------------------
