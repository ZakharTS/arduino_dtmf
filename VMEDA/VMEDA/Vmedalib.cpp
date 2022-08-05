//
// Created by Vladimir Moshchuk on 4.08.22.
//

#include "Vmedalib.h"


std::string Vmedalib::encode(const std::string &InputString, std::string &key) {
    std::string OutputString;
    std::string keytemp;
    std::string temp;
    OutputString = shiftRandomEncoding(InputString, keytemp);
    for(int i = 0; i < OutputString.size(); i++){
       temp += OutputString[i];
       temp += keytemp[i];
    }
    OutputString = ShiftRandomEncodingDeep(temp, key);
    return OutputString;
}


std::string Vmedalib::decode(std::string &InputString, std::string &key) {
    std::string OutputString;

    OutputString = ShiftRandomDecodingDeep(InputString, key);

    return  ShiftRandomDecoding(OutputString);
}


std::string Vmedalib::shiftRandomEncoding(const std::string& InputString, std::string& key) {
    unsigned int charkey;

    std::string OutputString;

    std::mt19937_64 engine;
    std::random_device device;
    engine.seed(device());

    for(char i : InputString){
        charkey = device() % 10;
        key += std::to_string(charkey);
        OutputString +=(char)((int)i + charkey);
    }
    return OutputString;
}


std::string Vmedalib::ShiftRandomDecoding(const std::string& InputString) {
    std::string OutputString;
    std::string temps;

    for( int i =0; i < InputString.size()/2; i++){
        if(2*i+1 > InputString.size()){
            break;
        }
        temps = InputString[2*i+1];
        OutputString +=(char)(((int)InputString[2*i]) - std::stoi(temps));
    }
    return OutputString;
}


std::string Vmedalib::ShiftRandomEncodingDeep(const std::string &InputString, const std::string &key) {
    int count = key.size();
    std::string OutputString;
    for(int index = 0; index < InputString.size(); index++){
        count--;
        if(index > key.size()){
            count = key.size();
        }
       OutputString += (char)((int)InputString[index] - (int)key[count / 2 - 1]);
    }
    return OutputString;
}

std::string Vmedalib::ShiftRandomDecodingDeep(const std::string &InputString, const std::string &key) {
    int count = key.size();
    std::string OutputString;
    for(int index = 0; index < InputString.size(); index++){
        count--;
        if(index > key.size()){
            count = key.size();
        }
       OutputString += (char)((int)InputString[index]+(int)key[count/2 - 1]);
    }
    return OutputString;
}

std::string Vmedalib::GenPass(int n){
    int c=0,s=0;
    std::string D;
    char C;
    std::mt19937_64 engine;
    std::random_device device;
    engine.seed(device());
    do {
        for (int z = 0; z < n; z++) {
            C =  alphnum[engine() %  sizeof(alphnum) - 1];
            D += C;
            if (isdigit(C)) {
                c++;
            }
            if (C == '!' || C == '@' || C == '$' || C == '%' || C == '^' || C == '&' || C == '*' || C == '#') {
                s++;
            }
        }
    } while (n>2 && (s == 0 || c == 0));

    return D;
}



