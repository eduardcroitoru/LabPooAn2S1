
#ifndef DESKTOP_SONG_H
#define DESKTOP_SONG_H
#include <string>
#include <vector>
#include <ostream>
#include "Song.h"
using namespace std;

class Song {
    int idSong;
    string name;
    float durata;

public:
    static int counter;

    Song();
    Song(const string &name, float durata);
    Song(const Song& s);
    virtual ~Song();

    friend ostream &operator<<(ostream &os, const Song &song);

    bool operator<(const Song &rhs) const;
    bool operator>(const Song &rhs) const;
    bool operator<=(const Song &rhs) const;
    bool operator>=(const Song &rhs) const;

    bool operator==(const Song &rhs) const;


    const string &getName() const;
    void setName(const string &name);
    int getIdSong() const;
    float getDurata() const;
    void setDurata(float durata);
};


#endif
