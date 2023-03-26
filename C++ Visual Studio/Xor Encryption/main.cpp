#include <iostream>
#include <string>
using namespace std;





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

std::string encrypt(std::string value, std::string key) {
	
	string text = value;

	std::string e1 = XOR_Encryption(text, key);
	stream2hex(e1, e1, true);
	return e1;
}

std::string decrypt(std::string value, std::string key) {

	string text = value;

	hex2stream(text, text);
	std::string d1 = XOR_Encryption(text, key);

	return d1;
}




int main() {

	std::string key = "u8skjnandkrem=)^!.<pS>(=_=)";
	//example
    std::string str = "hello world";


	std::string encryptedvalue=encrypt(str,key);
	cout << "Encrypted Value:" << encryptedvalue << endl;



	std::string decryptedvalue = decrypt(encryptedvalue,key);
	cout << "Decrypted Value:"<<decryptedvalue << endl;


}