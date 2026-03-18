#include <iostream>






class second {
    public:
    int a = 10;

    second(){

    }

    void show(){
        std::cout << "print from second: " << a << std::endl;
    }
};

class first  {
    public:
    second sekon;

    first()
    {
    }
};

int main(){

    first obj;
    obj.sekon.show();
    return 0;
}   