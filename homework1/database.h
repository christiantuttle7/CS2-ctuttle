#pragma once

#include <sstream>
#include <fstream>
#include "movie.h"


namespace databases{
    class database{
        private:
            movies::movie *movieDatabase[100];
            int numberOfMovies;
            


        public:
            database();
            ~database();
            void addMovie();
            void removeMovie();
            void printMovies();
            void searchForMovie();
            void exportMovies();

    };


};
