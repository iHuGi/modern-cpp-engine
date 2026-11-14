#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>

// ============================================================================
// Domain Model: Song
// ============================================================================
class Song {
    friend std::ostream& operator<<(std::ostream& os, const Song& s);

    std::string name;
    std::string artist;
    int rating;

public:
    Song() : name{"Unknown"}, artist{"Unknown"}, rating{1} {}
    Song(std::string name, std::string artist, int rating)
        : name{std::move(name)}, artist{std::move(artist)}, rating{rating} {}

    const std::string& get_name() const { return name; }
    const std::string& get_artist() const { return artist; }
    int get_rating() const { return rating; }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << std::setw(28) << std::left << s.name
       << std::setw(22) << std::left << s.artist
       << "[" << s.rating << "/5]";
    return os;
}

// ============================================================================
// Defensive CLI Input Helpers (Zero Stream Buffer Pollution)
// ============================================================================
std::string read_non_empty_line(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            return "";
        }
        // Accept any letters, numbers, symbols, or punctuation as long as not blank
        if (input.find_first_not_of(" \t\r\n") != std::string::npos) {
            return input;
        }
        std::cout << "[!] Input cannot be empty. Try again.\n";
    }
}

int read_validated_int(const std::string& prompt, int min_val, int max_val) {
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line)) {
            return min_val;
        }

        std::istringstream iss{line};
        int value{};
        char trailing{};
        if ((iss >> value) && !(iss >> trailing) && value >= min_val && value <= max_val) {
            return value;
        }
        std::cout << "[!] Invalid number. Enter an integer between "
                  << min_val << " and " << max_val << ".\n";
    }
}

char read_menu_choice() {
    std::string line;
    std::cout << "\nEnter selection: ";
    if (!std::getline(std::cin, line) || line.empty()) {
        return '\0';
    }
    return static_cast<char>(std::toupper(static_cast<unsigned char>(line[0])));
}

// ============================================================================
// Minimalist Display Functions
// ============================================================================
void display_menu() {
    std::cout << "\n======================================================\n"
              << "F - Play First Song\n"
              << "N - Play Next Song\n"
              << "P - Play Previous Song\n"
              << "A - Add Song(s)\n"
              << "D - Delete Current Song\n"
              << "L - List Playlist\n"
              << "Q - Quit\n"
              << "======================================================" << std::endl;
}

void play_current_song(const std::list<Song>& playlist,
                       std::list<Song>::const_iterator current_song) {
    if (playlist.empty() || current_song == playlist.end()) {
        std::cout << "[!] Playlist is empty. Add songs first.\n";
        return;
    }
    std::cout << "Playing -> " << *current_song << std::endl;
}

void display_playlist(const std::list<Song>& playlist,
                      std::list<Song>::const_iterator current_song) {
    std::cout << "\n--- Current Playlist ---------------------------------\n";
    if (playlist.empty()) {
        std::cout << "[Playlist is empty]\n";
        return;
    }

    for (auto it = playlist.cbegin(); it != playlist.cend(); ++it) {
        std::cout << (it == current_song ? "-> " : "   ") << *it << '\n';
    }
    std::cout << "------------------------------------------------------" << std::endl;
}

// ============================================================================
// Main Application Loop
// ============================================================================
int main() {
    std::list<Song> playlist{
        {"God's Plan",        "Drake",                     5},
        {"Never Be The Same", "Camila Cabello",            5},
        {"Pray For Me",       "The Weeknd and K. Lamar",   4},
        {"The Middle",        "Zedd, Maren Morris & Grey", 5},
        {"Wait",              "Maroon 5",                  4},
        {"Whatever It Takes", "Imagine Dragons",           3}
    };

    auto current_song = playlist.begin();
    display_playlist(playlist, current_song);
    play_current_song(playlist, current_song);

    char selection{};
    do {
        display_menu();
        selection = read_menu_choice();

        switch (selection) {
            case 'F': {
                if (playlist.empty()) {
                    std::cout << "[!] Playlist is empty.\n";
                    break;
                }
                current_song = playlist.begin();
                play_current_song(playlist, current_song);
                break;
            }

            case 'N': {
                if (playlist.empty()) {
                    std::cout << "[!] Playlist is empty.\n";
                    break;
                }
                ++current_song;
                if (current_song == playlist.end()) {
                    current_song = playlist.begin();
                }
                play_current_song(playlist, current_song);
                break;
            }

            case 'P': {
                if (playlist.empty()) {
                    std::cout << "[!] Playlist is empty.\n";
                    break;
                }
                if (current_song == playlist.begin()) {
                    current_song = playlist.end();
                }
                --current_song;
                play_current_song(playlist, current_song);
                break;
            }

            case 'A': {
                int count = read_validated_int("How many songs do you want to add (1-50)? ", 1, 50);
                bool was_empty = playlist.empty();

                for (int i = 0; i < count; ++i) {
                    std::cout << "\n[Song " << (i + 1) << " of " << count << "]\n";
                    std::string name = read_non_empty_line("Song name: ");
                    std::string artist = read_non_empty_line("Artist: ");
                    int rating = read_validated_int("Rating (1-5): ", 1, 5);

                    playlist.push_back(Song{std::move(name), std::move(artist), rating});
                }

                if (was_empty && !playlist.empty()) {
                    current_song = playlist.begin();
                }
                std::cout << "\n[+] Added " << count << " song(s) to the playlist.\n";
                break;
            }

            case 'D': {
                if (playlist.empty() || current_song == playlist.end()) {
                    std::cout << "[!] Playlist is already empty.\n";
                    break;
                }

                std::cout << "[-] Deleted: " << current_song->get_name() << '\n';
                // erase() invalidates only the erased node and returns the next valid iterator
                current_song = playlist.erase(current_song);

                if (playlist.empty()) {
                    current_song = playlist.end();
                } else if (current_song == playlist.end()) {
                    current_song = playlist.begin();
                }
                break;
            }

            case 'L': {
                display_playlist(playlist, current_song);
                break;
            }

            case 'Q': {
                std::cout << "Exiting playlist engine. Goodbye!\n";
                break;
            }

            default: {
                std::cout << "[!] Invalid selection. Choose F, N, P, A, D, L, or Q.\n";
                break;
            }
        }
    } while (selection != 'Q');

    return 0;
}