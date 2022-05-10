#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <limits>

using namespace std;

class records{
    public:
        string artist, album;

    void addRecord(){
        cout << "Input Artist: \n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, artist);
        cout << "Input Album: \n";
        getline(cin, album);
    }    
    void rmRecord(){
        int removeID;
        cout << "Type ID of record to remove: ";
        cin >> removeID;
        cout << "\nRecord removed.\n";
    }    
};

int main(){

    int menuOption;
    records record;
    

    while(menuOption != 4){

    
    cout << "\nMAIN MENU\n";
    cout << "1. ADD RECORD\n";
    cout << "2. VIEW ALL RECORDS\n";
    cout << "3. REMOVE RECORD\n";
    cout << "4. EXIT\n";
    cout << "\nSelection: ";
    cin >> menuOption;
    cout << endl;
    
    
    fstream recordList("RecordList.txt", ios::in | ios::out | ios::app);
    int id = 0; 
    if(recordList.is_open()){
                 
                string idCheck;

                while (!recordList.eof()){
                    getline(recordList, idCheck);
                    id++;
                } recordList.close();
            } else cout << "File cannot be opened.\n";

        switch(menuOption){
            
            case 1: 

                          
                if(!recordList.is_open()){
                    fstream recordList("RecordList.txt", ios::in | ios::out | ios::app);
                    record.addRecord();
                    cout << "\nRecord added successfully.\n";
                    recordList << id << "|" << record.artist << "|" << record.album << endl;
                    recordList.close();
                } else cout << "File is not on the given path\n";
            break;

            case 2: 
            
            if(!recordList.is_open()){
                fstream recordList("RecordList.txt", ios::in | ios::out | ios::app);
                string line;
                recordList.seekg(0, ios::beg);
                while (!recordList.eof()){
                    getline(recordList, line);
                    cout << line << endl;
                }
                recordList.close();
                } else cout << "File cannot be opened.\n";    
                
            break;

            case 3:
            record.rmRecord();
            if(recordList.is_open()){

            }
            
            break;

            case 4:
            cout << "Exiting...\n";
            break;

            default:
            cout << "Please pick a valid option\n";
            cin.clear();
            cin.ignore();
            break;
            } 

    }

}