#ifndef GAKKI_ALGORITHM_H
#define GAKKI_ALGORITHM_H
#include <iostream>
#include <map>
#include <iterator>
#include <functional>
#include <string>

#define GAKKI_REGISTER_ALGORITHM(key,name,foo) \
     void register_algorithm_##key(){ \
          gakki::registerAlgorithm(key,name,foo); \
     }\
    __attribute__((constructor)) void register_algorithm_##key();

/**gcc中有一个关键字__attribute__((constructor)) ，使用该关键字声明的函数就可以在main函数之前执行。
*__attribute__((constructor))与全局变量类构造函数的执行顺序的问题，\
*一般全局变量是在__attribute__(constructor)前完成初始化的，
*但是如果__attribute__是在main函数所在的文件，而全局变量是在其他文件定义的，
*那么__attribute__(constructor)就会在全局变量类构造函数前面执行，
*
*不过，在执行__attribute__时已经看到了全局变量的定义，
*只是没有执行全局变量的构造函数（这里，如果全局变量不是类，而是普通类型，是没有问题的）
*/


namespace gakki{
//算法示例容器
extern std::map<int,std::pair< std::string,std::function<void ()> > > algorithms;

//注册算法示例，key为调用指令，description为算法名,algorithmsExample为算法示例
extern void registerAlgorithm(int key,std::string name,std::function<void ()> algorithmsExample);

//展示全部的算法
extern void showAlgorithms();

//调用指定指令的算法
extern void invokeAlgorithm(int key);

}
#endif // GAKKI_ALGORITHM_H
