#include <iostream>
#include "gakki_algorithm.h"
#include <string>

using namespace std;

void foo()
{
   std::cout<<"������foo"<<std::endl;
}
GAKKI_REGISTER_ALGORITHM(1,string("dasds"),foo);


int main()
{
    gakki::showAlgorithms();
    cout<<"�������ָ�ѡ��Ҫչʾ���㷨ʾ��:"<<endl;
    int input;
    cin>>input;
    gakki::invokeAlgorithm(input);
    return 0;
}

