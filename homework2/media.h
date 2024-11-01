#pragma once 
#include <iostream>
#include <string>

using namespace std;



namespace medias{
    class media{
        private:
            string id;
            string title;
            int year;
        public:
            void setId(string);
            void setTitle(string);
            void setYear(int);
            string getId();
            string getTitle();
            int getYear();
    };

};