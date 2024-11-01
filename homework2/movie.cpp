

#include "movie.h"




movies::movie::movie(){
    director = "";
    genre = "";
    rating = 0.0;

}




string movies::movie::getDirector(){
    return director;
}

string movies::movie::getGenre(){
    return genre;
}

float  movies::movie::getRating(){
    return rating;
}

            
void movies::movie::setDirector(string directorSetter){
    director = directorSetter;
}
            
void movies::movie::setGenre(string genreSetter){
    genre = genreSetter;
}
            
void movies::movie::setRating(float ratingSetter){
    rating = ratingSetter;
}

