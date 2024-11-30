#pragma once

#include <sstream>
#include <fstream>
#include "movie.h"
#include "media.h"
#include "music.h"
#include "tvshows.h"


namespace databases{
    class database{
        private:
            string name;
            movies::movie *movieDatabase[100];
            int numberOfMovies;
            musics::music *musicDatabase[100];
            int numberOfMusic;
            tvshows::tvshow *tvshowDatabase[100];
            int numberOfTvShows;
            


        public:
            database();
            ~database();
            void addMedia();
            void removeMedia();
            void printMedia();
            void searchMedia();
            void exportMedia();
            

    };


};
