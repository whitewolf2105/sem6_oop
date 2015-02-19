#include <iomanip>
#include "IOFormat.h"
using namespace std;
IOFormat::IOFormat(int width,
                   int precision1,
                   int precision2,
                   int precision3,
                   ios::fmtflags flags):IOParams(width,
                                            precision1,
                                            precision2,
                                            precision3,
                                            flags)
{
    Init();
}

void IOFormat::Init(){
    f1.setParams(this);
    f2.setParams(this);
    i.setParams(this);
    c1.setParams(this);
    c2.setParams(this);
}

std::istream& IOFormat::inputFrom(std::istream& is){
    if(is==cin)
        cout<<"Введите вещественное число #1."<<endl;
    is>>f1;
    if(!is.good()){
        cerr<<"Ошибка ввода вещественного числа #1!"<<endl;
        clear(is);
    }
    if(is==cin)
        cout<<"Введите целое число."<<endl;
    is>>i;
    if(!is.good()){
        cerr<<"Ошибка ввода целого числа!"<<endl;
        clear(is);
    }
    if(is==cin)
        cout<<"Введите символ #1."<<endl;
    is>>c1;
    if(!is.good()){
        cerr<<"Ошибка ввода символа #1!"<<endl;
        clear(is);
    }
    if(is==cin)
        cout<<"Введите вещественное число #2."<<endl;
    is>>f2;
    if(!is.good()){
        cerr<<"Ошибка ввода вещественного числа #2!"<<endl;
        clear(is);
    }
    if(is==cin)
        cout<<"Введите символ #2."<<endl;
    is>>c2;
    if(!is.good()){
        cerr<<"Ошибка ввода символа #2!"<<endl;
        clear(is);
    }
    return is;
}

std::ostream& IOFormat::printTo(std::ostream& os) const {
    os<<f1<<
        c1<<
        i<<
        c2<<
        f2;
    return os;
}



