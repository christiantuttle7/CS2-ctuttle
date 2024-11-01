#pragma once 
#include <iostream>
#include <string>
#include "media.h"

using namespace std;


namespace movies{

    class movie : public medias::media{

        private:
            string director;
            string genre;
            float rating;
        
        public:
            movie();
        
            //getters
            
            string getDirector();
            string getGenre();
            float getRating();

            //setters
            void setDirector(string);
            void setGenre(string);
            void setRating(float);

    };



};