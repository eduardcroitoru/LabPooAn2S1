#include <iostream>
#include "Singer.h"
#include "Song.h"
#include "Playlist.h"
#include "ListaCantece.h"
#include "Album.h"
#include<bits/stdc++.h>
#include <typeinfo>//
#include "SingletoneMenu.h"


SingletoneMenu::SingletoneMenu()
{
}

SingletoneMenu::~SingletoneMenu()
{
}

int Singer::id = 0;
int Song::counter = 0;

void SingletoneMenu::meniu()
{
    Singer s;
    Song a("primu", 1.34);
    Song b("aldoilea", 2.44);
    Song c("altreilea", 3.2);
    Song d("alpatrulea", 2.49);
    s = s+a;
    s = s+b;
    s = s+c;
    s = s+d;

    cout<<"singer: ";
    cout<<s;
    cout<<endl;
    cout<<"shuffle: ";

    std::vector<Song> rez = s.shuffle();
    for(unsigned int i=0; i<rez.size(); i++)
        cout<<rez[i].getName()<<" ";

    cout<<endl<<endl;

    Playlist p;
    p = p+a;
    p = p+b;
    p = p+c;
    p = p+d;

    cout<<p<<endl;
    cout<<p.playRandom();

    cout<<endl<<endl;
    Album alb;
    alb = alb+a;
    alb = alb+b;
    alb = alb+c;
    alb.setAlbumname("numelealb");
    alb.setCantaret(s);
    cout<<alb<<endl<<endl;

    std::vector<ListaCantece*> lista;
    lista.push_back(&alb);          //upcast
    lista.push_back(&p);            //upcast

    for(auto el : lista){
        cout<<*el<<endl;    //upcast
    }

    cout<<endl<<endl;

    try{
        for(auto el : lista){   //DOWNCAST
            if (typeid(*el) == typeid(alb)){
                cout<< dynamic_cast<Album&> (*el)<<endl;
            }
            else if (typeid(*el) == typeid(p)){
                cout<<"Playlist "<< dynamic_cast<Playlist&> (*el)<<endl;
            }
            else{
                throw -1;
            }
        }
    }catch(...){
        cout<<"s-a adaugat ceva gresit in lista";
    }
}