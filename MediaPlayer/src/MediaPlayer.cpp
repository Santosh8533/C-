#include "MediaPlayer.h"

int MediaPlayer::songID = 0;

MediaPlayer::MediaPlayer()
{
    //ctor
}

MediaPlayer::~MediaPlayer()
{
    //dtor
}

void MediaPlayer::displayPlaylist(){

    cout<< "------------------------------------------------------------\n" ;
    cout << "Song Title \t\t\t Singer \t    Duration\n";
    cout << "-----------------------------------------------------------\n";

    list<Song> copyPlaylist;
    list<Song> :: iterator copy_it;
    copyPlaylist = playlist;
    copy_it = copyPlaylist.begin();

    for(copy_it = copyPlaylist.begin(); copy_it!=copyPlaylist.end(); copy_it++)
        cout << copy_it->title << "\t\t" << copy_it->singer <<"\t \t" << copy_it->duration << endl;

    cout << "---------------------------------------------------------\n\n";
}

void MediaPlayer::displayCurrentSong(){
    cout << it->title << "\t\t" << it->singer <<"\t \t" << it->duration << endl;

}

void MediaPlayer::openPlayer(){
    it = playlist.begin();
}

void MediaPlayer::addToPlaylist(string songName, string singer, float duration, int position){

    //Store the song details
    s.title =  songName;
    s.singer = singer;
    s.duration = duration;
    s.ID = ++songID;

    //Insert song at a specified position
    list<Song>::iterator copy_it;
    it = playlist.begin();
    copy_it = it;

    if(position <= playlist.size()){
        for(int i=0;i<position;i++){
            it++; //moving the iterator to the position
        }
        playlist.insert(it,s);
        //cout<< "Song added to the playlist:\t" << it->title << endl;
    }

    // insert at the end of the playlist if the position is greater than the size of the playlist
    else{
        playlist.push_back(s);
    }

    //retain the original position of the iterator
    if(playlist.size() == 1){
        it = playlist.begin(); //if it is the only song in the playlist
    }
    else
        it = copy_it; //original position

}

bool MediaPlayer::goToFirst(){

    if(playlist.empty() || it == playlist.begin()){
        return false;
    }

    else{
        it = playlist.begin();
        return true;
    }

}


bool MediaPlayer::goToPrev(){

    if(playlist.empty() || it == playlist.begin()){
        return false;
    }
    else{
        it--;
        return true;
    }
}

bool MediaPlayer::goToLast(){

    if(playlist.empty()){
        return false;
    }
    else if(++it==playlist.end()){
        it--; //point to the last song
        cout << "Last song is playing currently" << endl;
        return false;
    }
    else{
        it = playlist.end();
        it--; //Point to the last song
        return true;
    }
}

//Go to next song
bool MediaPlayer::goToNext(){

    //if playlist is empty
    if(playlist.empty()){
        return false;
    }
    it++;
    //if iterator points to the last song
    if(it == playlist.end()){

        it--; //Points to the last song
        return false;
    }
    else{
        return true;
    }
    //general case
} //end of function


//Reverse the playlist
void MediaPlayer::reversePlaylist(){
    playlist.reverse();
} //end of function

//Go to a particular song
bool MediaPlayer::goToSong(string title){

    //check if playlist is empty
    if(playlist.empty()){
        return false;
    }
    //create a new iterator to retain original iterator position
    list<Song>::iterator copy_it;
    copy_it = it;
    //Perform string match between input string and the playlist
    it = playlist.begin();
    while(it!=playlist.end()){
        if(title.compare(it->title)==0){
            return true;
        }
        it++;
    }
    //restore the original iterator position in the case of song not found
    it = copy_it;
    return false;
}//end of the program

//Remove the song from the playlist

struct removeSong{
    string title;
    bool operator()(const Song &s){
        return (s.title.compare(title)==0);
    }
};

bool MediaPlayer::removeFromPlaylist(string SongTitle){
    removeSong rs;
    rs.title = SongTitle;
    playlist.remove_if(removeSong(rs));
} // end of the function

//sort the songs by the title
bool byTitle(Song first,Song second){
    return first.title < second.title;
}//end of the function

void MediaPlayer::sortTitle(){
    playlist.sort(byTitle);
}// end of the function

//sort the songs by the duration
bool byDuration(Song first, Song second){
    return first.duration < second.duration;
}

void MediaPlayer::sortDuration(){
    playlist.sort(byDuration);
}




