#include "gakki_algorithm.h"

std::map<int,std::pair< std::string,std::function<void ()> > > gakki::algorithms;

void gakki::registerAlgorithm(int key,std::string name,std::function<void ()> algorithmsExample)
{
    if(!algorithms.count(key))
    {
        algorithms.insert(std::make_pair(key,std::make_pair(name,algorithmsExample)));
    }
    else
    {
        std::cout<<"ע���㷨"<<name<<"ʧ��,����ָ��:"<<key<<"�Ѿ���ע��"<<std::endl;
    }
}

void gakki::showAlgorithms()
{
    for(auto iter=algorithms.begin(),end=algorithms.end(); iter!=end; iter++)
    {
        std::cout<<iter->first<<" : "<<(iter->second).first<<std::endl;
    }
}

void gakki::invokeAlgorithm(int key)
{
    if(algorithms.count(key)){
        algorithms[key].second();
    }else{
        std::cout<<"����ָ��"<<key<<"δ�󶨺���"<<std::endl;
    }
}
