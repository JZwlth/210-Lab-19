// COMSC-210 | Lab 19 | Zhaoyi Zheng

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <forward_list>

using namespace std;

// Function prototypes
double generateRandomRating();
void readCommentsFromFile(const string& filename, vector<string>& comments);

class Movie {
private:
    string title;
    forward_list<double> ratings;
    forward_list<string> comments;

public:
    // Constructor
    Movie(const string& title);

    // Methods to add ratings and comments
    void addRating(double rating);
    void addComment(const string& comment);

    // Method to display the reviews and calculate average rating
    void displayReviews() const;
};


int main() {
    // Seed random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 5.0);

    // Read comments from file
    vector<string> comments;
    readCommentsFromFile("comments.txt", comments);

    if (comments.size() < 4) {
        cerr << "Not enough comments in the file." << endl;
        return 1;
    }

    // Create Movie objects
    Movie movie1("The Great Adventure");
    Movie movie2("Mystery of the Night");

    return 0;
}

double generateRandomRating() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_real_distribution<> dis(1.0, 5.0);

    double rating = dis(gen);
    rating = round(rating * 10) / 10.0; // Round to one decimal place
    return rating;
}

