//
// Created by Vladimir Moshchuk on 4.08.22.
//

#ifndef VMEDA_VMEDALIB_H
#define VMEDA_VMEDALIB_H

#import <string>
#import <random>

class Vmedalib {

private:
    constexpr static const char alphnum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";

    static std::string pass;

    static std::string shiftRandomEncoding(const std::string& InputString, std::string& key);


    static std::string ShiftRandomDecoding(const std::string& InputString);

    static std::string ShiftRandomEncodingDeep(const std::string &InputString, const std::string &key);

    static std::string ShiftRandomDecodingDeep(const std::string &InputString, const std::string &key);
public:
    //For encoding and decoding
    static std::string encode(const std::string &InputString, std::string &key);

    static std::string decode(std::string &InputString, std::string &key);
    //for generating key
    static std::string GenPass(int n);


};


#endif //VMEDA_VMEDALIB_H
