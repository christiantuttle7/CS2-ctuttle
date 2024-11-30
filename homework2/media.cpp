#include "media.h"



void medias::media::setID(string x){
    id = x;
}

            
void medias::media::setTitle(string x){
    title = x;
}          
            
            
            
            
            
void medias::media::setYear(int x){
    year = x;
}
            
string medias::media::getID(){
    return id;
}


string medias::media::getTitle(){
    return title;
}
            
int medias::media::getYear(){
    return year;
}