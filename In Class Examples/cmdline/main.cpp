#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
//int main(int argc, char *argv[])
{
    cout<<"There are "<<argc<<" items on the command line"<<endl
        <<"They are:"<<endl;
    for(int i =0; i < argc; i++)
//       cout<<"argv["<<i<<"] = "<<argv[i]<<endl;
         cout<<"argv["<<i<<"] = "<<*(argv+i)<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
