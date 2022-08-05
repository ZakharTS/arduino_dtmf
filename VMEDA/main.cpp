#import <iostream>
#import "VMEDA/Vmedalib.h"
int main() {
    std::string encode;
   std::string key =  Vmedalib::GenPass(32);
   std::string text = "Привет Захар!";
  encode = Vmedalib::encode(text, key);
  std::cout<<encode<<std::endl;
  std::cout<<key<<std::endl;
   std::cout << Vmedalib::decode(encode, key);
    return 0;
}
