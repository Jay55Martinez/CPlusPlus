// Jay Martinez -- assingment 6 -- 6/20/23
#include <string>

class Song {
    public:
        // overloaded constructor
        Song(std::string t, std::string aut, int year, double l) {
            this->title = t;
            this->author = aut;
            this->release_year = year;
            this->length = l;
        }

        // copy constructor
        Song(const Song& other) {
            title = other.title;
            author = other.author;
            release_year = other.release_year;
            length = other.length;
        }

        // copy assignment operator
        Song& operator=(const Song& other) {
            if (this != &other) {
                title = other.title;
                author = other.author;
                release_year = other.release_year;
                length = other.length;
            }
            return *this;
        }

        // move constructor
        Song(Song&& other) {
            title = std::move(other.title);
            author = std::move(other.author);
            release_year = other.release_year;
            other.release_year = 0;
            length = other.length;
            other.length = 0;
        }

        // move assignment operator
        Song& operator=(Song&& other) {
            if (this != &other) {
                title = std::move(other.title);
                author = std::move(other.author);
                release_year = other.release_year;
                other.release_year = 0;
                length = other.length;
                other.length = 0;
            }
            return *this;
        }

        // deconstructor
        ~Song() {}

        bool operator==(const Song& other) const {
            return (title == other.title) && (author == other.author) && (release_year == other.release_year) && (length == other.length);
        }

        bool operator!=(const Song& other) const {
            return !(*this == other);
        }
        
    private:
        std::string title;
        std::string author;
        int release_year;
        double length;
};