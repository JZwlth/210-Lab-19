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

