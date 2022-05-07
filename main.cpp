#include <iostream>
#include <string.h>

class records{
    private:
        char *artist, *album, *country, *label;
        double *rating;
    public:
        records() {
            artist = new char[40];
            album = new char[40];
            country = new char[40];
            label = new char [40];
            rating = new double;
        }
        void addRecord();
        void removeRecord();
        void editRecord();
        void showRecord();

        void addWishlist();
        void removeWishlist();
        void editWishlist();
        void showWishlist();

        int search(char[], char[]);

};

void records::addRecord(){
    std::cout << "\nEnter artist name:\n"; 
    std::cin.getline(artist,40);
    std::cout << "Enter album name:\n"; 
    std::cin.getline(album,40);
    std::cout << "Enter country of origin:\n"; 
    std::cin.getline(country,40);
    std::cout << "Enter label name:\n"; 
    std::cin.getline(label,40);
    std::cout << "Enter rating /5:\n"; 
    std::cin >> *rating;
    
}

void records::removeRecord(){

}

void records::editRecord(){
    std::cout << "\nEnter artist name:\n"; 
    std::cin.getline(artist,40);
    std::cout << "Enter album name:\n"; 
    std::cin.getline(album,40);
    std::cout << "Enter country of origin:\n"; 
    std::cin.getline(country,40);
    std::cout << "Enter label name:\n"; 
    std::cin.getline(label,40);
    std::cout << "Enter rating /5:\n"; 
    std::cin >> *rating;
}

void records::showRecord(){
    std::cout << "Artist: " << artist; 
    std::cout << "Album: " << album;
    std::cout << "Country: " << country;
    std::cout << "Label: " << label;
    std::cout << "Rating: " << rating;
}

int main(){
    records records;
    records.addRecord();

    /*struct{
        std::string artist;
        std::string album;
        std::string country;
        std::string label;
        double rating;
    } addRecStruct;*/

    
    return 0;
}
