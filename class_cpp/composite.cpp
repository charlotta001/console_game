#include <iostream>




class second {
    public:
    int a = 10;
    int c = 30;

    second(){
        this->a = 10;
        this->c = 30;
    }

    void show(){
        std::cout << "print from second: " << a << std::endl;
        std::cout << "c: " << c << std::endl;
    }
};

class first  {
    public:
    int b = 19;
    second* sekon =  new second();

    first()
    {
    }

    void lihat(){
        std::cout << "b: " << b;
    }
};

int main(){

    // Name obj = { 1,2};
    // std::cout << obj.a << "||" << obj.b << std::endl;

    // alias objek = {3,4};
    // std::cout << objek.a <<"||" << objek.b << std::endl;
    // std::cout << obj.a <<"||" << obj.b << std::endl;

  
    int* l = new int[100];
    int k = 10;
    int* ptr = &k;
    int** ptrptr = &ptr;

    int o[2];
    o[0] =  90;
    o[1] =  40;
    int (*op)[2] = &o;
    std::cout << (*op)[2] << std::endl;

    l[0] = 19;
    l[1] = 29;
    std::cout << *(l) << std::endl; 
    std::cout << l[0] << std::endl; 
    std::cout << *(l + 1) << std::endl; 
    std::cout << l[1] << std::endl; 




    std::cout << "k: " << k << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "ptrptr: " << ptrptr << std::endl;
    std::cout << "=======================================" << std::endl;
    
    std::cout << "&k: " << (void*)&k << std::endl;
    std::cout << "&ptr: " << (void*)&ptr << std::endl;
    std::cout << "&ptrptr: " << (void*)&ptrptr << std::endl;
    std::cout << "=======================================" << std::endl;

    
    std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << "*ptrptr: " << *ptrptr << std::endl;
    std::cout << "=======================================" << std::endl;

    std::cout << "**ptrptr: " << **ptrptr << std::endl;
    

    // first* objek = new first();
    // objek->sekon->show();
    // objek->lihat();
    // first obj;
    // obj.sekon.show();
    // obj.lihat();

    return 0;
}   