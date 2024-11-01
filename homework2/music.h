#pragma once 
#include <iostream>
#include <string>
#include "media.h"

using namespace std;


namespace musics{

    class music : public medias::media{

        private:
            string composer;
            string genre;
            int numOfTracks;
            int totalPlaytime;
        
        public:
            music();
        
            //getters
            
            string getComposer();
            string getGenre();
            int getNumOfTracks();
            int getTotalPlaytime();

            //setters
            void setComposer(string);
            void setGenre(string);
            void setNumOfTracks(int);
            void setTotalPlaytime(int);

    };



};