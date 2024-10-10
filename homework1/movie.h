#pragma once 
#include <iostream>
#include <string>

using namespace std;


namespace movies{

    class movie{

        private:
            string titleId;
            string title;
            int year;
            string director;
            string genre;
            float rating;
        
        public:
            movie();
        
            //getters
            string getTitleID();
            string getTitle();
            int getYear();
            string getDirector();
            string getGenre();
            float getRating();

            //setters
            void setTitleID(string);
            void setTitle(string);
            void setYear(int);
            void setDirector(string);
            void setGenre(string);
            void setRating(float);

    };



};