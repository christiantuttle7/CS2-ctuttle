#pragma once 
#include <iostream>
#include <string>
#include "media.h"

using namespace std;


namespace tvshows{

    class tvshow : public medias::media{

        private:
            string genre;
            float rating;
            int numOfEpisodes;
        
        public:
            tvshow();
        
            //getters
            
            string getGenre();
            float getRating();
            int getNumOfEpisodes();

            //setters
            void setGenre(string);
            void setRating(float);
            void setNumOfEpisodes(int);

    };



};