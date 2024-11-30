
#include "tvshows.h"

tvshows::tvshow::tvshow(){
    
}



string tvshows::tvshow::getGenre(){
    return genre;
}
            
float tvshows::tvshow::getRating(){
    return rating;
}
            
int tvshows::tvshow::getNumOfEpisodes(){
    return numOfEpisodes;
}

//setters
void tvshows::tvshow::setGenre(string newGenre){
    genre = newGenre;
}

void tvshows::tvshow::setRating(float newRating){
    rating =  newRating;
}

void tvshows::tvshow::setNumOfEpisodes(int newEpisodes){
    numOfEpisodes = newEpisodes;
}

