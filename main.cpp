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
    Movie(const string& title);

    void addRating(double rating);
    void addComment(const string& comment);
    void displayReviews() const;
};


int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 5.0);

    vector<string> comments;
    readCommentsFromFile("comments.txt", comments);

    if (comments.size() < 4) {
        cerr << "Not enough comments in the file." << endl;
        return 1;
    }

    Movie movie1("The Great Adventure");
    Movie movie2("Mystery of the Night");

    // Assign comments and ratings to movies
    // For movie1
    for (int i = 0; i < 2; ++i) {
        double rating = generateRandomRating();
        movie1.addRating(rating);
        movie1.addComment(comments[i]);
    }

    for (int i = 2; i < 4; ++i) {
        double rating = generateRandomRating();
        movie2.addRating(rating);
        movie2.addComment(comments[i]);
    }

    vector<Movie> movies;
    movies.push_back(movie1);
    movies.push_back(movie2);


    for (const auto& movie : movies) {
        movie.displayReviews();
        cout << endl;
    }

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

void readCommentsFromFile(const string& filename, vector<string>& comments) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening comments file: " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(infile, line)) {
        if (!line.empty()) {
            comments.push_back(line);
        }
    }
    infile.close();
}

Movie::Movie(const string& title) : title(title) {
}

void Movie::addRating(double rating) {
    ratings.push_front(rating); // Add to the head of the list
}

void Movie::addComment(const string& comment) {
    comments.push_front(comment); // Add to the head of the list
}

void Movie::displayReviews() const {
    cout << "Reviews for \"" << title << "\":" << endl;

    vector<double> ratingsVec(ratings.begin(), ratings.end());
    vector<string> commentsVec(comments.begin(), comments.end());

    if (ratingsVec.size() != commentsVec.size()) {
        cerr << "Mismatch in number of ratings and comments." << endl;
        return;
    }

    double sum = 0.0;
    int count = ratingsVec.size();

    cout << fixed << setprecision(1);
    for (int i = count - 1; i >= 0; --i) {
        cout << "    > Review #" << (count - i) << ": " << ratingsVec[i] << ": " << commentsVec[i] << endl;
        sum += ratingsVec[i];
    }

    if (count > 0) {
        double average = sum / count;
        cout << fixed << setprecision(5);
        cout << "    > Average: " << average << endl;
    } else {
        cout << "No reviews to display." << endl;
    }
}