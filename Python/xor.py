key1 = "u8skjnandkrem=)^!.<pS>(=_=)"
def XOR_Encryption(toBeEncrypted, sKey):
    sEncrypted = []
    iKey = len(sKey)
    iIn = len(toBeEncrypted)
    x = 0
    for i in range(iIn):
        val = ord(toBeEncrypted[i]) ^ ord(sKey[x])
        sEncrypted.append(chr(val))
        x += 1
        if x == iKey:
            x = 0
    return "".join(sEncrypted)


def stream2hex(str):
    hexstr = bytearray(str, 'utf-8').hex()
    hexstr = hexstr.upper()
    return hexstr

def hex2stream(hexstr):
    str = bytearray.fromhex(hexstr).decode('utf-8')
    return str

def encrypt(toBeEncrypted):
    sEncrypted = XOR_Encryption(toBeEncrypted, key1)
    aba=stream2hex(sEncrypted)
    return aba

def decrypt(encrypted):
    sDecrypted = hex2stream(encrypted)
    sDecrypted = XOR_Encryption(sDecrypted, key1)
    return sDecrypted

def main():

	#example
    example= "hello world"
    encrypted=encrypt(example)
    print("Encrypted Value:"+encrypted)

    decrypted=decrypt(encrypted)
    print("Decrypted Value:"+decrypted)

if __name__ == "__main__":
    main()