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
        std::cout<<"注册算法"<<name<<"失败,调用指令:"<<key<<"已经被注册"<<std::endl;
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
        std::cout<<"调用指令"<<key<<"未绑定函数"<<std::endl;
    }
}
