#include "Message.hpp"
#include <cstdlib>
#include <iostream>

int main(){
    Message message1("say hello");
    std::cout<< message1 <<std::endl;
    Message message2("say bye");
    std::cout<< message2 <<std::endl;
    return EXIT_SUCCESS;
}