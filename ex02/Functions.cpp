#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int random = std::rand() % 3;
    if (random == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return (new A);
    }        
    else if (random == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return (new B);
    }
    else
    {
        std::cout << "Generated: C" << std::endl;
        return (new C);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void identify(Base& p)
{

}