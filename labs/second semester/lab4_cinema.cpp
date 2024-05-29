#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

const std::string FILENAME = "movies_schedule.txt";

struct Movie {
    int movieID;
    std::string title;
    std::string director;
    int yearReleased;
    std::string genre;
};

std::vector<Movie> load_data() {
    std::vector<Movie> data;
    std::ifstream file(FILENAME);
    if (!file.is_open()) {
        std::ofstream outfile(FILENAME);
        outfile.close();
        return data;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        Movie movie;
        ss >> movie.movieID >> movie.title >> movie.director >> movie.yearReleased >> movie.genre;
        data.push_back(movie);
    }
    file.close();
    return data;
}

void save_data(const std::vector<Movie>& data) {
    std::ofstream file(FILENAME);
    for (const auto& movie : data) {
        file << movie.movieID << " " << movie.title << " " << movie.director << " " << movie.yearReleased << " " << movie.genre << std::endl;
    }
    file.close();
}

void add_record(std::vector<Movie>& data) {
    Movie movie;
    std::cout << "Enter Movie ID: ";
    std::cin >> movie.movieID;
    std::cout << "Enter Title: ";
    std::cin >> movie.title;
    std::cout << "Enter Director: ";
    std::cin >> movie.director;
    std::cout << "Enter Year Released: ";
    std::cin >> movie.yearReleased;
    std::cout << "Enter Genre: ";
    std::cin >> movie.genre;
    data.push_back(movie);
    save_data(data);
}

void edit_record(std::vector<Movie>& data) {
    int id;
    std::cout << "Enter Movie ID for edit : ";
    std::cin >> id;

    for (auto& movie : data) {
        if (movie.movieID == id) {
            std::cout << "Enter new title (leave it empty to save the current value): ";
            std::string new_title;
            std::cin.ignore();
            getline(std::cin, new_title);
            if (!new_title.empty()) movie.title = new_title;

            std::cout << "Enter new director (leave it empty to save the current value): ";
            std::string new_director;
            getline(std::cin, new_director);
            if (!new_director.empty()) movie.director = new_director;

            std::cout << "Enter new year released (leave it empty to save the current value): ";
            std::string new_year_str;
            getline(std::cin, new_year_str);
            if (!new_year_str.empty()) movie.yearReleased = std::stoi(new_year_str);

            std::cout << "Enter new genre (leave it empty to save the current value): ";
            std::string new_genre;
            getline(std::cin, new_genre);
            if (!new_genre.empty()) movie.genre = new_genre;

            save_data(data);
            return;
        }
    }
    std::cout << "An entry with this Movie ID wasn't found" << std::endl;
}

void delete_record(std::vector<Movie>& data) {
    int id;
    std::cout << "Enter Movie ID for delete: ";
    std::cin >> id;

    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->movieID == id) {
            data.erase(it);
            save_data(data);
            return;
        }
    }
    std::cout << "An entry with this Movie ID wasn't found" << std::endl;
}

void find_record(const std::vector<Movie>& data) {
    int id;
    std::cout << "Enter Movie ID to find: ";
    std::cin >> id;

    for (const auto& movie : data) {
        if (movie.movieID == id) {
            std::cout << "Movie ID: " << movie.movieID << ", Title: " << movie.title << ", Director: " << movie.director << ", Year Released: " << movie.yearReleased << ", Genre: " << movie.genre << std::endl;
            return;
        }
    }
    std::cout << "An entry with this Movie ID wasn't found." << std::endl;
}

void show_menu() {
    std::cout << "\nSelect an action:\n";
    std::cout << "1. Add an entry\n";
    std::cout << "2. Edit an entry\n";
    std::cout << "3. Delete an entry\n";
    std::cout << "4. Find an entry\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter an action: ";
}

int main() {
    std::vector<Movie> data = load_data();
    while (true) {
        show_menu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            add_record(data);
            break;
        case 2:
            edit_record(data);
            break;
        case 3:
            delete_record(data);
            break;
        case 4:
            find_record(data);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Wrong. Try again." << std::endl;
        }
    }
    return 0;
}
