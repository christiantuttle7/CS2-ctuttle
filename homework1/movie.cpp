

#include "movie.h"




movies::movie::movie(){
    titleId = "";
    title = "";
    year = 0;
    director = "";
    genre = "";
    rating = 0.0;

}


string movies::movie::getTitleID(){
    return titleId;
}


string movies::movie::getTitle(){
    return title;
}

int movies::movie::getYear(){
    return year;
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


//setters
void movies::movie::setTitleID(string Id){
    titleId = Id;

}

void movies::movie::setTitle(string titleSetter){
    title = titleSetter;
}
            
void movies::movie::setYear(int yearSetter){
    year = yearSetter;
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

