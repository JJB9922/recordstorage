#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class records{
    public:
        string artist;
        string album;

    void addRecord(){
        cout << "Input Artist: \n";
        cin >> artist;
        cout << "Input Album: \n";
        cin >> album;
    }    
};

int main ()
{
    

    
	return 0;
}
