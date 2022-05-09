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

int main(){

    int menuOption;
    int id;

    records record;
    fstream recordList("RecordList.txt", ios::in | ios::out | ios::app);

    while(menuOption != 3){

    cout << "\nMAIN MENU\n";
    cout << "1. ADD RECORD\n";
    cout << "2. VIEW ALL RECORDS\n";
    cout << "3. EXIT\n";
    cout << "\nSelection: ";
    cin >> menuOption;
    cout << endl;

//Next task: incrementing ID
        switch(menuOption){
            case 1:   
                record.addRecord();
                         
                if(recordList.is_open()){
                    cout << "\nRecord added successfully.\n";
                    recordList << "{" << id << "," << record.artist << "," << record.album << "}" << endl;
            break;

            case 2:
                recordList.seekg(0);
                    string line;
                    while (recordList.good()){
                        getline(recordList, line);
                        cout << line << endl;
                    }

                    } else cout << "File is not there on the given path\n";
            break;
            default:
            if(menuOption=3){
                cout << "Exiting...";
            }else cout << "\nPlease pick a valid option";
            break;   
        }
    }

}