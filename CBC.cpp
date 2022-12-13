#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/sha.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
#include <string>
#include <fstream>
#include <random>
#include <sstream>
#include <iomanip>

using namespace std;




int main(int argc, char **argv)
{
    using namespace CryptoPP;
    /*string pass;
    string readfile;
    string writefile;
    unsigned op;
    cout<<"Cipher ready. Input pass: ";
    cin>>pass;
    cout<<"Pass loaded\n";
    cout<<"Input readfile path";
    cin>>readfile;
    cout<<"Input writefile path";
    cin>>writefile;*/

    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF);
    unsigned long long numericsalt = distribution(generator);
    std::stringstream stream;
    stream << std::hex << numericsalt;
    std::string strsalt(stream.str());
    for (long unsigned int i =0;i<=strsalt.size();i++){
        strsalt[i] = toupper(strsalt[i]);
    }
    if (strsalt.size() < 16) {
        std::string strsalttemp =strsalt;
        for (unsigned i = strsalt.size(); i <16; i++){
            strsalttemp.insert (strsalttemp.begin(), '0');
        }
        strsalt = strsalttemp;
    }
    //StringSource(buffer, hash.DigestSize(), true, new HexEncoder(new FileSink(std::cout)));
    cout<<strsalt<<'\n';

/*    do {
        cout<<"Cipher ready. Input operation (0-exit, 1-
            encrypt, 2-decrypt): ";
            cin>>op;
            if (op > 2) {
        cout<<"Illegal operation\n";
    } else if (op >0) {
        cout<<"Cipher ready. Input text: ";
        cin>>text;
        if (isValid(text)) {
                if (op==1) {
                    cout<<"Encrypted text:
                        "<<encrypt(text)<<endl;
                } else {
                    cout<<"Decrypted text:
                        "<<decrypt(text)<<endl;
                }
            } else {
                cout<<"Operation aborted: invalid
                    text\n";
            }
        }
    } while (op!=0);*/
    return 0;
}