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

/**gcc����һ���ؼ���__attribute__((constructor)) ��ʹ�øùؼ��������ĺ����Ϳ�����main����֮ǰִ�С�
*__attribute__((constructor))��ȫ�ֱ����๹�캯����ִ��˳������⣬\
*һ��ȫ�ֱ�������__attribute__(constructor)ǰ��ɳ�ʼ���ģ�
*�������__attribute__����main�������ڵ��ļ�����ȫ�ֱ������������ļ�����ģ�
*��ô__attribute__(constructor)�ͻ���ȫ�ֱ����๹�캯��ǰ��ִ�У�
*
*��������ִ��__attribute__ʱ�Ѿ�������ȫ�ֱ����Ķ��壬
*ֻ��û��ִ��ȫ�ֱ����Ĺ��캯����������ȫ�ֱ��������࣬������ͨ���ͣ���û������ģ�
*/


namespace gakki{
//�㷨ʾ������
extern std::map<int,std::pair< std::string,std::function<void ()> > > algorithms;

//ע���㷨ʾ����keyΪ����ָ�descriptionΪ�㷨��,algorithmsExampleΪ�㷨ʾ��
extern void registerAlgorithm(int key,std::string name,std::function<void ()> algorithmsExample);

//չʾȫ�����㷨
extern void showAlgorithms();

//����ָ��ָ����㷨
extern void invokeAlgorithm(int key);

}
#endif // GAKKI_ALGORITHM_H
