#include <iostream>
#include <string>

using namespace std;

class Song
{
public:
    string title;
    Song *prev;
    Song *next;
    Song(string title) : title(title), next(nullptr), prev(nullptr)
    {
    }
};

class Playlist
{
private:
    Song *head;
    Song *tail;

public:
    Playlist() : head(nullptr), tail(nullptr) {}

    void addSong(string title)
    {
        Song *newSong = new Song(title);
        if (!head)
        {
            head = newSong;
            tail = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }
    bool removeSong(string title)
    {
        Song *temp = head;

        while (temp != nullptr)
        {
            if (temp->title == title)
            {
                if (temp->prev)
                {
                    temp->prev->next = temp->next;
                };
                if (temp->next)
                {
                    temp->next->prev = temp->prev;
                };
                if (temp == head)
                {
                    head = temp->next;
                };
                if (temp == tail)
                {
                    tail = temp->prev;
                };
                delete temp;
                return true;
            };
            temp = temp->next;
        }
        return false; // song not found
    }

    void displaySong()
    {
        Song *temp = head;
        while (temp != nullptr)
        {
            cout << temp->title << endl;
            temp=temp->next;
        }
    }
};

int main()
{
    Playlist dimPlaylist;
    dimPlaylist.addSong("All Gas No Brakes");
    dimPlaylist.addSong("Last one to know");
    dimPlaylist.addSong("Rocket man");
    dimPlaylist.addSong("Brunette");
    dimPlaylist.addSong("Head over heels");

    cout << "Current Playlist:" << endl;
    dimPlaylist.displaySong();

    dimPlaylist.removeSong("Rocket man");
    cout << "\nPlaylist after removing a song:" << endl;
    dimPlaylist.displaySong();

    return 0;
}