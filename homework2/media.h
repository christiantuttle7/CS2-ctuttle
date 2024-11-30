#pragma once 
#include <iostream>
#include <string>

using namespace std;



namespace medias{
    class media{
        private:
            string id;
            string title;
            string genre;
            int year;
        public:
            void setID(string);
            void setTitle(string);
            void setYear(int);
            void setGenre(string);
            string getID();
            string getTitle();
            int getYear();
            string getGenre();
    };

};