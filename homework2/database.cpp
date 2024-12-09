
#include "database.h"







databases::database::database(){

    //allocate memory
    for(int i = 0; i <100; i++){
        movieDatabase[i] = new movies::movie;
        musicDatabase[i] = new musics::music;
        tvshowDatabase[i] = new tvshows::tvshow;
    }
    

    //GETTING MOVIES
    //opening file
    ifstream movieFile ("movies.csv");

    //each line of the file will be put into this string
    string tempLine;

    string xtitleId;
    string xtitle;
    int xyear;
    string xdirector;
    string xgenre;
    float xrating;


    int movieCounter = 0;    
    while( getline(movieFile, tempLine, '\n')){
        stringstream line(tempLine);
        
        
        //get the title id and store it
        getline(line, xtitleId, ',' );
        movieDatabase[movieCounter]->setID(xtitleId);

        
        //get the title and store it
        getline(line, xtitle, ',' );
        movieDatabase[movieCounter]->setTitle(xtitle);

        //get the year, store as an int
        line >> xyear;
        line.ignore();

        movieDatabase[movieCounter]->setYear(xyear);

        //get the genre and store it
        getline(line, xgenre, ',');
        movieDatabase[movieCounter]->setGenre(xgenre);

        //get the rating, store as float
        line >> xrating;
        line.ignore();
        movieDatabase[movieCounter]->setRating(xrating);


        //get Director and store it
        getline(line, xdirector, ',');
        movieDatabase[movieCounter]->setDirector(xdirector);

        movieCounter++;
    }
    numberOfMovies = movieCounter;


   //GETTING MUSIC
    //opening file
    ifstream musicFile ("music.csv");
    //each line of the file will be put into this string
    string musictempLine;


    string xcomposer;

    int xplaytime, xtracks;

    



    int musicCounter = 0;    
    while( getline(musicFile, musictempLine, '\n')){
        stringstream musicline(musictempLine);
        
        
        //get the title id and store it
        getline(musicline, xtitleId, ',' );
        musicDatabase[musicCounter]->setID(xtitleId);

        
        //get the title and store it
        getline(musicline, xtitle, ',' );
        musicDatabase[musicCounter]->setTitle(xtitle);

        //get the year, store as an int
        musicline >> xyear;
        musicline.ignore();
        musicDatabase[musicCounter]->setYear(xyear);


        //getting the composer
        getline(musicline, xcomposer, ',');
        musicDatabase[musicCounter]->setComposer(xcomposer);



        //get the genre and store it
        getline(musicline, xgenre, ',');
        musicDatabase[musicCounter]->setGenre(xgenre);


        //get the palytime, store as int
        musicline >> xtracks;
        musicline.ignore();
        musicDatabase[musicCounter]->setNumOfTracks(xtracks);


        //get the rating, store as float
        musicline >> xplaytime;
        musicline.ignore();
        musicDatabase[musicCounter]->setTotalPlaytime(xplaytime);

        musicCounter++;

    }

    numberOfMusic = musicCounter;






    //GETTING TV SHOWS
    //opening file
    ifstream tvshowFile ("tvshows.csv");
    //each line of the file will be put into this string
    string tvshowtempLine;



    string xtvshow;
    int xepisodes;
    



    int tvshowCounter = 0;    
    while( getline(tvshowFile, tvshowtempLine, '\n')){
        stringstream tvshowline(tvshowtempLine);
        
        
        //get the title id and store it
        getline(tvshowline, xtitleId, ',' );
        tvshowDatabase[tvshowCounter]->setID(xtitleId);

        
        //get the title and store it
        getline(tvshowline, xtitle, ',' );
        tvshowDatabase[tvshowCounter]->setTitle(xtitle);

        //get the year, store as an int
        tvshowline >> xyear;
        tvshowline.ignore();
        tvshowDatabase[tvshowCounter]->setYear(xyear);




        //get the genre and store it
        getline(tvshowline, xgenre, ',');
        tvshowDatabase[tvshowCounter]->setGenre(xgenre);


        //get the palytime, store as int
        tvshowline >> xrating;
        tvshowline.ignore();
        tvshowDatabase[tvshowCounter]->setRating(xrating);


        //get the rating, store as float
        tvshowline >> xepisodes;
        tvshowline.ignore();
        tvshowDatabase[tvshowCounter]->setNumOfEpisodes(xepisodes);
        tvshowCounter++;

    }

    numberOfTvShows = tvshowCounter;




    movieFile.close();
    musicFile.close();
    tvshowFile.close();
 
 

    
}

//deconstructor
databases::database::~database(){
    for(int i = 0; i < 100; i++){
        delete movieDatabase[i];
    }
}





//print out all of the movies
void databases::database::printMedia(){
    int mediaType;
    cout << endl;
    cout << "What type of media would you like to display" << endl;
    cout << "1. Movies\n2. Music\n3. TV Shows" << endl;
    cin >> mediaType;
    cin.ignore();


    //display movies
    if(mediaType == 1){
        for(int i = 0; i < numberOfMovies; i++){
            cout << "Movie " << i+1 <<": " << endl;
            cout << "Title: " <<movieDatabase[i]->getTitle() << endl;
            cout << "Director: " <<movieDatabase[i]->getDirector() << endl;
            cout <<"ID: " << movieDatabase[i]->getID() << endl;
            cout <<"Genre: " <<movieDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<movieDatabase[i]->getYear() << endl;
            cout <<"Rating: " <<movieDatabase[i]->getRating() << endl;
            cout << endl;
        }
    }
    //display music
    else if(mediaType == 2){
        for(int i = 0; i < numberOfMusic; i++){
            cout << "Album " << i+1 <<": " << endl;
            cout << "Title: " <<musicDatabase[i]->getTitle() << endl;
            cout << "Composer: " <<musicDatabase[i]->getComposer() << endl;
            cout <<"ID: " << musicDatabase[i]->getID() << endl;
            cout <<"Genre: " <<musicDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<musicDatabase[i]->getYear() << endl;
            cout <<"Number Of Tracks: " <<musicDatabase[i]->getNumOfTracks() << endl;
            cout <<"Total Playtime: " <<musicDatabase[i]->getTotalPlaytime() << endl;
            cout << endl;
        }

    }
    //display tv shows
    else if(mediaType == 3){
        for(int i = 0; i < numberOfTvShows; i++){
            cout << "Tv Show " << i+1 <<": " << endl;
            cout << "Title: " <<tvshowDatabase[i]->getTitle() << endl;
            cout <<"ID: " << tvshowDatabase[i]->getID() << endl;
            cout <<"Genre: " <<tvshowDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<tvshowDatabase[i]->getYear() << endl;
            cout <<"Number Of Episodes: " <<tvshowDatabase[i]->getNumOfEpisodes() << endl;
            cout <<"Rating: " <<tvshowDatabase[i]->getRating() << endl;
            cout << endl;
        }
    }
    
}



void databases::database::addMedia(){
    string tempTitle, tempTitleId,  tempGenre, tempDirector;
    int tempYear;
    float tempRating;

    int choice;
    cout << "What type of media would you like to add: \n1. Movie\n2. Music\n3. TV show" << endl;
    cin >> choice; 
    cin.ignore();  
    
    //First asking the user some questions that pertain to all media
    //title
    cout << "What is the title of the media? " ;
    getline(cin, tempTitle);
    

    //title ID
    cout <<"What is the id of th media? ";
    getline(cin, tempTitleId);

    //year
    cout << "What is the year?";
    cin >> tempYear;
    cin.ignore();


    //genre
    cout << "What is the genre? ";
    getline(cin, tempGenre);

    


    if(choice == 1){
        
        movieDatabase[numberOfMovies]->setTitle(tempTitle);
        movieDatabase[numberOfMovies]->setID(tempTitleId);
        movieDatabase[numberOfMovies]->setYear(tempYear);

        //rating
        cout <<"What is the rating? ";
        cin >> tempRating;
        cin.ignore();
        movieDatabase[numberOfMovies]->setRating(tempRating);

        //director
        cout << "Who is the director? ";
        getline(cin, tempDirector);
        movieDatabase[numberOfMovies]->setDirector(tempDirector);

        numberOfMovies++;
        cout << "Movie Added" << endl;

    }
    if(choice == 2){
        musicDatabase[numberOfMusic]->setTitle(tempTitle);
        musicDatabase[numberOfMusic]->setID(tempTitleId);
        musicDatabase[numberOfMusic]->setYear(tempYear);


         //composer
         string tempComposer;
        cout <<"Who is the composer? ";
        getline(cin, tempComposer);
        musicDatabase[numberOfMusic]->setComposer(tempComposer);

        //number of trracks
        int tempNumOfTracks;
        cout << "Whats the number of tracks? ";
        cin >> tempNumOfTracks;
        cin.ignore();
        musicDatabase[numberOfMusic]->setNumOfTracks(tempNumOfTracks);

        //playtime
        int tempPlaytime;
        cout << "Whats the total playtime? ";
        cin >> tempPlaytime;
        cin.ignore();
        musicDatabase[numberOfMusic]->setTotalPlaytime(tempPlaytime);

        //increment number of music
        numberOfMusic++;
        cout << "Music Added" << endl;


    }

        if(choice == 3){
        tvshowDatabase[numberOfTvShows]->setTitle(tempTitle);
        tvshowDatabase[numberOfTvShows]->setID(tempTitleId);
        tvshowDatabase[numberOfTvShows]->setYear(tempYear);


         //composer
         string tempGenre;
        cout <<"What is the genre? ";
        getline(cin, tempGenre);
        tvshowDatabase[numberOfMusic]->setGenre(tempGenre);

        //number of trracks
        int tempNumOfEps;
        cout << "Whats the number of tracks? ";
        cin >> tempNumOfEps;
        tvshowDatabase[numberOfMusic]->setNumOfEpisodes(tempNumOfEps);

        //playtime
        float tempRating;
        cout << "Whats the rating? ";
        cin >> tempRating;
        cin.ignore();
        tvshowDatabase[numberOfMusic]->setRating(tempRating);

        //increment number of music
        numberOfTvShows++;
        cout << "Music Added" << endl;


    }



}




void databases::database::searchMedia(){
    string searchInput;

    bool mediaFound = false;

    cout << endl;
    cout <<"What is the title/ID/Genre: ";
    getline(cin, searchInput);



    //go through every movie and see if the search input matches to movie
    for(int i = 0; i < numberOfMovies; i++){
        if(movieDatabase[i]->getID() == searchInput||
            movieDatabase[i]->getGenre() == searchInput ||
            movieDatabase[i]->getTitle() == searchInput ){
            cout << "Title: " <<movieDatabase[i]->getTitle() << endl;
            cout << "Director: " <<movieDatabase[i]->getDirector() << endl;
            cout <<"ID: " << movieDatabase[i]->getID() << endl;
            cout <<"Genre: " <<movieDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<movieDatabase[i]->getYear() << endl;
            cout <<"Rating: " <<movieDatabase[i]->getRating() << endl;
            cout << endl;
            mediaFound = true;
        }
    }

    //go through every music and see if the search input matches any of the music
    for(int i = 0; i < numberOfMusic; i++){
        if(musicDatabase[i]->getID() == searchInput||
            musicDatabase[i]->getGenre() == searchInput ||
            musicDatabase[i]->getTitle() == searchInput){
            mediaFound = true;
            cout << "Title: " <<musicDatabase[i]->getTitle() << endl;
            cout << "Composer: " <<musicDatabase[i]->getComposer() << endl;
            cout <<"ID: " << musicDatabase[i]->getID() << endl;
            cout <<"Genre: " <<musicDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<musicDatabase[i]->getYear() << endl;
            cout << "Number of Tracks: " << musicDatabase[i]->getNumOfTracks() << endl;
            cout <<"Playtime: " <<musicDatabase[i]->getTotalPlaytime() << endl;
            cout << endl;
    }
    }

    //go through every tv show and see if the search input matches te movie
    for(int i = 0; i < numberOfMovies; i++){
        if(tvshowDatabase[i]->getID() == searchInput||
            tvshowDatabase[i]->getGenre() == searchInput ||
            movieDatabase[i]->getTitle() == searchInput ){
            cout << "Title: " <<tvshowDatabase[i]->getTitle() << endl;
            cout <<"ID: " << tvshowDatabase[i]->getID() << endl;
            cout <<"Genre: " <<tvshowDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<tvshowDatabase[i]->getYear() << endl;
            cout <<"Rating: " <<tvshowDatabase[i]->getRating() << endl;
            cout << "Number of Episodes: " <<tvshowDatabase[i]->getNumOfEpisodes() << endl;
            cout << endl;
        }
    }

    if(!mediaFound){
        cout << "No Media Found" << endl;
      
    }


    
}



void databases::database::removeMedia(){
    
    //finding out the id of the movie the user would like to delete
    bool mediaFound = false;
    int mediaType;
    string chosenMedia;
    cout <<"What is the ID of the media you would like to remove: ";
    cin >>chosenMedia;
    cin.ignore();
    int chosenMediaNumber;

    //finding out which movie has the id the user provided
    for(int k = 0; k < numberOfMovies; k++){
        if(movieDatabase[k]->getID() == chosenMedia){
            chosenMediaNumber = k;
            mediaType = 1;
            mediaFound = true;
        }
        if(musicDatabase[k]->getID() == chosenMedia){
            chosenMediaNumber = k;
            mediaType =2;
            mediaFound = true;
        }
        if(tvshowDatabase[k]->getID() == chosenMedia){
            chosenMediaNumber = k;
            mediaType = 3;
            mediaFound = true;
        }
    }
    
    //move every media that is ahead of the movie being deleted down by 1
    if(mediaFound){
        //if chosen media is a movie
        if(mediaType == 1){
            delete movieDatabase[chosenMediaNumber];
            for(int i = chosenMediaNumber; i < numberOfMovies; i++){
                movieDatabase[i]->setDirector(movieDatabase[i+1]->getDirector());
                movieDatabase[i]->setTitle(movieDatabase[i+1]->getTitle());
                movieDatabase[i]->setID(movieDatabase[i+1]->getID());
                movieDatabase[i]->setGenre(movieDatabase[i+1]->getGenre());
                movieDatabase[i]->setYear(movieDatabase[i+1]->getYear());
                movieDatabase[i]->setRating(movieDatabase[i+1]->getRating());
            }
            numberOfMovies --;
            std::cout << "Movie Removed" << endl;;
        }
        //if chosen media is music
        if(mediaType == 2){
            delete musicDatabase[chosenMediaNumber];
            for(int i = chosenMediaNumber; i < numberOfMovies; i++){
                musicDatabase[i]->setComposer(musicDatabase[i+1]->getComposer());
                musicDatabase[i]->setTitle(musicDatabase[i+1]->getTitle());
                musicDatabase[i]->setID(musicDatabase[i+1]->getID());
                musicDatabase[i]->setGenre(musicDatabase[i+1]->getGenre());
                musicDatabase[i]->setYear(musicDatabase[i+1]->getYear());
                musicDatabase[i]->setNumOfTracks(musicDatabase[i+1]->getNumOfTracks());
                musicDatabase[i]->setTotalPlaytime(musicDatabase[i+1]->getTotalPlaytime());
            }
            numberOfMusic --;
            std::cout << "Music Removed" << endl;;
        }
        //if chosen media is a tv show
        if(mediaType == 3){
            delete tvshowDatabase[chosenMediaNumber];
            for(int i = chosenMediaNumber; i < numberOfMovies; i++){
                tvshowDatabase[i]->setNumOfEpisodes(tvshowDatabase[i+1]->getNumOfEpisodes());
                tvshowDatabase[i]->setTitle(tvshowDatabase[i+1]->getTitle());
                tvshowDatabase[i]->setID(tvshowDatabase[i+1]->getID());
                tvshowDatabase[i]->setGenre(tvshowDatabase[i+1]->getGenre());
                tvshowDatabase[i]->setYear(tvshowDatabase[i+1]->getYear());
                tvshowDatabase[i]->setRating(tvshowDatabase[i+1]->getRating());
               
            }
            numberOfMusic --;
            std::cout << "Music Removed" << endl;;
            
        }
    }
    else{
        cout << "Media Not Found " << endl;
    }
   

}





void databases::database::exportMedia(){
    ofstream movieExport ("moviesExport.csv");
    ofstream musicExport ("musicExport.csv");
    ofstream tvshowExport ("tvshowExport.csv");


    //exporting the movie list to a different csv.
    for(int i = 0; i < numberOfMovies; i++){
        
        movieExport <<movieDatabase[i]->getID() << ',';
        movieExport  <<movieDatabase[i]->getTitle() << ',';
        movieExport << movieDatabase[i]->getYear() << ',';
        movieExport  <<movieDatabase[i]->getGenre() << ',';
        movieExport  <<movieDatabase[i]->getRating() << ',';
        movieExport  <<movieDatabase[i]->getDirector() << endl;
        
    }

    for(int i = 0; i < numberOfMusic; i++){
        
        musicExport <<musicDatabase[i]->getID() << ',';
        musicExport  <<musicDatabase[i]->getTitle() << ',';
        musicExport << musicDatabase[i]->getYear() << ',';
        musicExport  <<musicDatabase[i]->getGenre() << ',';
        musicExport  <<musicDatabase[i]->getComposer() << ',';
        musicExport  <<musicDatabase[i]->getTotalPlaytime() << ',';
        musicExport  <<musicDatabase[i]->getNumOfTracks() << endl;
        
    }


    for(int i = 0; i < numberOfMovies; i++){
        
        tvshowExport <<tvshowDatabase[i]->getID() << ',';
        tvshowExport  <<tvshowDatabase[i]->getTitle() << ',';
        tvshowExport << tvshowDatabase[i]->getYear() << ',';
        tvshowExport  <<tvshowDatabase[i]->getGenre() << ',';
        tvshowExport  << tvshowDatabase[i]->getRating() << ',';
        tvshowExport  << tvshowDatabase[i]->getNumOfEpisodes() << endl;
        
    }

    
    movieExport.close();
    musicExport.close();
    tvshowExport.close();
}








