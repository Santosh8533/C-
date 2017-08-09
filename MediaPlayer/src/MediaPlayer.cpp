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

    if(playlist.empty() || it == playlist.begin()){
        return false;
    }
    else{
        it = playlist.end();
        re
    }
}

