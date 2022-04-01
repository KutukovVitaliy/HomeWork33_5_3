//
// Created by kvitadmin on 01.04.2022.
//

#ifndef HOMEWORK33_5_3_REGISTER_H
#define HOMEWORK33_5_3_REGISTER_H
#include <vector>
#include <iostream>

template<typename T1, typename T2>
struct Pair{
    T1 key;
    T2 value;
    Pair(T1 inKey , T2 inValue) : key(inKey), value(inValue){}
};

template<typename T1, typename T2>
class Register{
    std::vector<Pair<T1, T2>>* ptrRegister;
public:
    Register()
    {
        ptrRegister = new std::vector<Pair<T1, T2>>;
    }
    ~Register()
    {
        delete ptrRegister;
    }
    void AddElement(Pair<T1, T2>& el)
    {
        ptrRegister->template emplace_back(el);
    }
    int RemoveElements(T1 inKey)
    {
        int count = 0;
        typename std::vector<Pair<T1, T2>>::iterator it;
        for(it = ptrRegister->begin(); it != ptrRegister->end(); ++it)
        {
            if(it->key == inKey)
            {
                it = ptrRegister->erase(it);
                it--;
                count++;
            }
        }
        return count;
    }
    std::vector<Pair<T1, T2>> FindElements(T1 inKey)
    {
        std::vector<Pair<T1, T2>> result;
        typename std::vector<Pair<T1, T2>>::iterator it;
        for(it = ptrRegister->begin(); it != ptrRegister->end(); ++it)
        {
            if(it->key == inKey)
            {
                result.template emplace_back(Pair<T1, T2>{it->key, it->value});
            }
        }
        return result;
    }
    friend std::ostream& operator<< (std::ostream& os, Register<T1, T2>& reg)
    {
        if(reg.ptrRegister->empty()) os << "Register is empty!";
        typename std::vector<Pair<T1, T2>>::iterator it;

        for(it = reg.ptrRegister->begin(); it != reg.ptrRegister->end(); ++it)
        {
            os << it->key << ":" << it->value << " ";
        }
        os << std::endl;
    }
};


#endif //HOMEWORK33_5_3_REGISTER_H
