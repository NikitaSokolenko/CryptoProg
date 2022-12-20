#pragma once
#include <string>
#include <map>

using namespace std;

class Opts
{
private:
	std::string orig_file = "original.txt";
	std::string encr_file = "encrypted.bin";
	std::string decr_file = "decrypted.txt";
	std::string key_file = "key.hex";
	std::string iv_file = "iv.hex";
	std::string key;
	bool encrypt = false;
	bool decrypt = false;
    void usage(const char* progName);
public:
    Opts(int argc, char **argv);
    bool CheckFiles();
};
