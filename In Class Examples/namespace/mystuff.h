#ifndef MYSTUFF_H
#define MYSTUFF_H
#include <iostream>
#include <cstdlib>

using namespace std;

namespace english
{
    void hello();
    void goodbye();
    namespace slang
    {
      void hello();
      void goodbye();
    }
}


namespace french
{
   void hello();
   void goodbye();
}
#endif // MYSTUFF_H
