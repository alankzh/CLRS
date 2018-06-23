#include <iostream>
#include "gakki_algorithm.h"
#include <string>

using namespace std;

void foo()
{
   std::cout<<"调用了foo"<<std::endl;
}
GAKKI_REGISTER_ALGORITHM(1,string("dasds"),foo);


int main()
{
    gakki::showAlgorithms();
    cout<<"输入调用指令，选择要展示的算法示例:"<<endl;
    int input;
    cin>>input;
    gakki::invokeAlgorithm(input);
    return 0;
}

