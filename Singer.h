#ifndef DESKTOP_SINGER_H
#define DESKTOP_SINGER_H
#include <cstring>
#include <string>
#include <vector>
#include <ostream>
#include "Song.h"

using namespace std;

class Singer {
private:
    int idSinger;
    string nume;
    int an_lansare;
    string gen_muzical;
    std::vector <Song> songs;

public:
    static int id;
    Singer();
    virtual ~Singer();
    Singer(const string &nume, int anLansare, const string &genMuzical, const vector<Song> &songs);

    Singer(const Singer& s);
    Singer &operator=(const Singer& s);
    friend ostream &operator<<(ostream &os, const Singer &singer);
    Singer operator+(const Song& s);

    int getIdSinger() const;
    const string &getNume() const;
    void setNume(const string &nume);
    int getAnLansare() const;
    void setAnLansare(int anLansare);
    const string &getGenMuzical() const;
    void setGenMuzical(const string &genMuzical);
    const vector<Song> &getSongs() const;
    void setSongs(const vector<Song> &songs);

    std::vector<Song> shuffle();    //amesteca ordinea cantecelor artistului
};


#endif
