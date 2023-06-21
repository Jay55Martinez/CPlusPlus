// Jay Martinez -- assingment 6 -- 6/20/23
#include <string>

class Book {
    public:
        // overloaded constructor
        Book(std::string t, std::string aut, int year) {
            this->title = t;
            this->author = aut;
            this->release_year = year;
        }

        // copy constructor
        Book(const Book& other) {
            title = other.title;
            author = other.author;
            release_year = other.release_year;
        }

        // copy assignment operator
        Book& operator=(const Book& other) {
            if (this != &other) {
                title = other.title;
                author = other.author;
                release_year = other.release_year;
            }
            return *this;
        }

        // move constructor
        Book(Book&& other) {
            title = std::move(other.title);
            author = std::move(other.author);
            release_year = other.release_year;
            other.release_year = 0;
        }

        // move assignment operator
        Book& operator=(Book&& other) {
            if (this != &other) {
                title = std::move(other.title);
                author = std::move(other.author);
                release_year = other.release_year;
                other.release_year = 0;
            }
            return *this;
        }

        // deconstructor
        ~Book() {}

        bool operator==(const Book& other) const {
            return (title == other.title) && (author == other.author) && (release_year == other.release_year);
        }

        bool operator!=(const Book& other) const {
            return !(*this == other);
        }
        
    private:
        std::string title;
        std::string author;
        int release_year;
};