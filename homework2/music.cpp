
#include "music.h"


musics::music::music(){
    cout << "cool" << endl;
}


string musics::music::getComposer(){
    return composer;
}
                    
string musics::music:: getGenre(){
    return genre;
}
int musics::music::getNumOfTracks(){
    return numOfTracks;
}
            
int musics::music::getTotalPlaytime(){
    return totalPlaytime;
}



//setters
void musics::music::setComposer(string newComposer){
    composer = newComposer;
}

void musics::music::setGenre(string newgenre){
    genre = newgenre;
}
            
void musics::music::setNumOfTracks(int newNumOfTracks){
    numOfTracks = newNumOfTracks;
}
            
void musics::music::setTotalPlaytime(int newPlaytime){
    totalPlaytime = newPlaytime;
}