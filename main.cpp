#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <limits>

using namespace std;

class records{
    public:
        string artist, album, removeID;

    void addRecord(){
        cout << "Input Artist: \n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, artist);
        cout << "Input Album: \n";
        getline(cin, album);
    }    
    void rmRecord(){
        cout << "Type ID of record to remove: ";
        cin.ignore(100, '\n');
        getline(cin, removeID);

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
                    id = ((rand() %10000000) + 999);
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
                } else cout << "File cannot be opened.\n";
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
            
            //removeID 
            if(!recordList.is_open()){
                    string line;
                    fstream recordList("RecordList.txt", ios::in | ios::out | ios::app);
                    record.rmRecord();
                    string search = record.removeID;
                    for(int lineCheck = 0; getline(recordList, line); lineCheck++){
                        if(line.find(search) != string::npos){
                            
                            }  
                        }
                        cout << "Removed record: (" << line << " | "<< search << ").";
                recordList.close();
                } else cout << "File cannot be opened.\n";
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