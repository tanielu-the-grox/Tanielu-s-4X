#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Enum for different types of celestial bodies
enum CelestialType {
    STAR,
    TERRESTRIAL,
    GAS_GIANT,
    BARREN,
    LAVA,
    NONE
};

// Enum for different types of entities on the celestial body
enum EntityType {
    SHIP,
    STATION,
    BOTH,
    PLACEHOLDER
};

// Structure to represent a celestial body
struct CelestialBody {
    CelestialType type;
    // Other attributes like size, resources, etc. can be added here
};

// Function to generate a random celestial body
CelestialBody generateCelestialBody() {
    CelestialBody body;
    body.type = static_cast<CelestialType>(rand() % 5); // Generating a random type
    return body;
}

// Function to generate a galaxy with random seeds
std::vector<std::vector<CelestialBody>> generateGalaxy(int size, int seed) {
    std::srand(seed); // Seed the random number generator
    std::vector<std::vector<CelestialBody>> galaxy(size, std::vector<CelestialBody>(size));

    // Generate stars and planets
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            CelestialBody body;
            int randNum = rand() % 10; // Generating a random number between 0 to 9
            if (randNum < 2) {
                // Place a star
                body.type = STAR;
            } else if (randNum < 5) {
                // Place a planet
                body.type = static_cast<CelestialType>(rand() % 4 + 1); // Choose a random planet type
            } else {
                // Empty space
                body.type = NONE;
            }
            galaxy[i][j] = body;
        }
    }

    return galaxy;
}

// Function to display the galaxy
void displayGalaxy(const std::vector<std::vector<CelestialBody>>& galaxy) {
    for (const auto& row : galaxy) {
        for (const auto& body : row) {
            char symbol = ' '; // Default empty space symbol

            // Check for types of celestial bodies
            if (body.type == STAR) {
                symbol = '*'; // Star symbol
            } else if (body.type == TERRESTRIAL) {
                symbol = 'T'; // Terrestrial planet symbol
            } else if (body.type == GAS_GIANT) {
                symbol = 'G'; // Gas giant symbol
            } else if (body.type == BARREN) {
                symbol = 'B'; // Barren planet symbol
            } else if (body.type == LAVA) {
                symbol = 'L'; // Lava planet symbol
            }

            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
}

// Class for Ship
class Ship {
public:
    string name;
    int capacity;
    int speed;

    Ship(string n, int c, int s) : name(n), capacity(c), speed(s) {}

    void display() const {
        cout << "Name: " << name << ", Capacity: " << capacity << ", Speed: " << speed << endl;
    }
};

// Class for Station
class Station {
public:
    string name;
    int capacity;
    int defense;

    Station(string n, int c, int d) : name(n), capacity(c), defense(d) {}

    void display() const {
        cout << "Name: " << name << ", Capacity: " << capacity << ", Defense: " << defense << endl;
    }
};

vector<Ship> ships;
vector<Station> stations;

// Function prototypes
void designShip();
void designStation();
void displayShips();
void displayStations();

int main() {
    const int GALAXY_SIZE = 100; // Increased galaxy size
    const int SEED = 42; // Seed for random number generation

    // Generate the galaxy
    std::vector<std::vector<CelestialBody>> galaxy = generateGalaxy(GALAXY_SIZE, SEED);

    // Display the galaxy
    displayGalaxy(galaxy);

    int choice;

    do {
        cout << "1. Design Ship\n";
        cout << "2. Design Station\n";
        cout << "3. Display Ships\n";
        cout << "4. Display Stations\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                designShip();
                break;
            case 2:
                designStation();
                break;
            case 3:
                displayShips();
                break;
            case 4:
                displayStations();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function definitions
void designShip() {
    string name;
    int capacity, speed;

    cout << "Enter ship name: ";
    cin >> name;
    cout << "Enter ship capacity: ";
    cin >> capacity;
    cout << "Enter ship speed: ";
    cin >> speed;

    Ship newShip(name, capacity, speed);
    ships.push_back(newShip);

    cout << "Ship designed successfully!\n";
}

void designStation() {
    string name;
    int capacity, defense;

    cout << "Enter station name: ";
    cin >> name;
    cout << "Enter station capacity: ";
    cin >> capacity;
    cout << "Enter station defense: ";
    cin >> defense;

    Station newStation(name, capacity, defense);
    stations.push_back(newStation);

    cout << "Station designed successfully!\n";
}

void displayShips() {
    cout << "---- List of Ships ----\n";
    for (const auto& ship : ships) {
        ship.display();
    }
}

void displayStations() {
    cout << "---- List of Stations ----\n";
    for (const auto& station : stations) {
        station.display();
    }
}
