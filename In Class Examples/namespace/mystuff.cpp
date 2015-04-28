#include <iostream>
#include <cstdlib>

using namespace std;


namespace english
{
    void hello()
    {
        cout<<"Good day, how are you?"<<endl;
    }

    void goodbye()
    {
        cout<<"Good bye"<<endl;
    }

    namespace slang
    {
      void hello()
      {
          cout<<"Yo dude, wha's up?"<<endl;
      }

      void goodbye()
      {
          cout<<"Get lost..."<<endl;
      }
    }
}


namespace french
{
   void hello()
   {
       cout<<"Bonjour, comment allez vous?"<<endl;
   }

   void goodbye()
   {
       cout<<"Au revoir"<<endl;
   }
}
