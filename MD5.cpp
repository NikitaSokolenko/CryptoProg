#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <string>
#include <fstream>



int main(int argc, char **argv)
{
    using namespace CryptoPP;

    Weak::MD5 hash;
    std::string msg;
    byte *buffer = new byte [hash.DigestSize()];
    std::ifstream file("/home/stud/C++Projects/prakt4/prakt4/strings.txt");
    if(!file) {
        std::cerr<< "fileproblems";
        abort();
    }

    while(getline(file, msg)) {
        std::cout<<"string:"<<msg<<'\n';
        hash.Update((const byte*)msg.data(), msg.size());
    }

    file.close();
    hash.Final(buffer);
    StringSource(buffer, hash.DigestSize(), true, new HexEncoder(new FileSink(std::cout)));
    std::cout<<std::endl;
    delete buffer;
    return 0;
}
