#include <iostream>
#include <cstdlib> // для функций strtol, exit
#include <unistd.h> // для функции getopt
#include <string>
#include "interface.h"
#include <fstream>
#include <map>
#include <exception>
// реализация интерфейса в виде класса
using namespace std;

Opts::Opts(int argc, char **argv)
{
    int opt;
    while ((opt = getopt(argc, argv, "k:o:f:e:d")) != -1) {
        switch (opt) {
        case 'k': // key
            key = optarg;
            break;
        case 'e': // encrypt
            encrypt = true;
            break;
        case 'd': // decrypt
            encrypt = true;
            break;
        case 'f': // file
            if(encrypt&&decrypt || !encrypt&&!decript){
            usage(argv[0]);
            break;}
            else{
            	if encrypt
            		encr_file = optarg;
            	if decrypt
            		decr_file = optarg;
            }
        case 'h': // -h help
        case '?': // неверный параметр
        case ':': // нет значения у параметра
            usage(argv[0]); // сообщить и завершить
        }
    }
}

void Opts::usage(const char* progName)
{
    std::cout<<"Usage: "<<progName<<" -b DataBaseName -n LogFileName -p Port \n";
    exit(1);
}

bool Opts::CheckFiles()
{
    try {
        std::ifstream file1(DataBaseName);
        if (file1.bad()) {
            throw std::invalid_argument("what");
        }
    } catch(std::invalid_argument err) {
        cout<<err.what()<<std::endl;
        exit(1);
    }
    try {
        std::ifstream file2(LogFileName);
        if (file2.bad()) {
            throw std::invalid_argument("what");
        }
    } catch(std::invalid_argument err) {
        cout<<err.what()<<std::endl;
        exit(1);
    }
    return true;
}
