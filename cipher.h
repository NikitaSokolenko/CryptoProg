#include <iostream>
#include <string>

#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/des.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>

class cipher{
private:
const char * orig_file;
const char * encr_file;
const char * decr_file;
const char * iv_file = "iv.hex";
const char * key_file = "key.hex";
std::string pwd;
public:
cipher(std::string o_file, std::string c_file, std::string key);
void encrypt();
void decrypt();
};
