#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdint>

// =====================================
// Data Structures
// =====================================
struct City {
    std::string name;
    std::int64_t population;
    double cost;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

// =====================================
// Function Prototypes
// =====================================
void display_tours_report(const Tours& tours);

// =====================================
// Main Execution
// =====================================
int main() {
    Tours tours { 
        "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
                },
            },
            { 
                "Argentina", {
                    { "Buenos Aires", 3010000, 723.77 } 
                }
            },
        }
    };

    // Call our formatted report engine
    display_tours_report(tours);

    return 0;
}

// =====================================
// Implementations
// =====================================
void display_tours_report(const Tours& tours) {
    // 1. Define table dimensions
    const int total_width = 70;
    const int field1_width = 20; // Country
    const int field2_width = 20; // City
    const int field3_width = 15; // Population
    const int field4_width = 15; // Cost

    // 2. Format and Center the Title
    // Calculate spaces needed to center the title
    int title_spaces = (total_width - tours.title.length()) / 2;
    std::cout << std::endl;
    std::cout << std::setw(title_spaces) << "" << tours.title << std::endl;
    std::cout << std::endl;

    // 3. Print Headers
    std::cout << std::setw(field1_width) << std::left << "Country"
              << std::setw(field2_width) << std::left << "City"
              << std::setw(field3_width) << std::right << "Population"
              << std::setw(field4_width) << std::right << "Price" 
              << std::endl;

    // Print a separator line
    std::cout << std::setfill('-') << std::setw(total_width) << "" << std::endl;
    std::cout << std::setfill(' '); // Reset fill to space

    // 4. Force floating point outputs to 2 decimal places (for currency)
    std::cout << std::fixed << std::setprecision(2);

    // 5. Iterate through the data using const references (no copying!)
    for (const auto& country : tours.countries) {
        // Flag to check if we are printing the first city of a country
        bool is_first_city = true;

        for (const auto& city : country.cities) {
            
            // If it's the first city, print the country name. Otherwise, print empty space.
            std::cout << std::setw(field1_width) << std::left
                      << (is_first_city ? country.name : "");

            // Print the rest of the city data
            std::cout << std::setw(field2_width) << std::left << city.name
                      << std::setw(field3_width) << std::right << city.population
                      << std::setw(field4_width) << std::right << city.cost 
                      << std::endl;
            
            is_first_city = false;
        }
    }

    // Print a bottom separator line
    std::cout << std::setfill('-') << std::setw(total_width) << "" << std::endl;
    
    // 6. State RESET (Best Practice)
    std::cout << std::setfill(' ') << std::left;
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);
}