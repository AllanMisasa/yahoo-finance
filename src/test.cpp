#include "quote.hpp"
#include <iostream>

int main() {
    Quote *snp500 = new Quote("^GSPC");

    snp500->getHistoricalSpots("2024-01-01", "2024-01-31", "1d");

    snp500->printSpots();

    /*
    try {
        Spot spot = snp500->getSpot("2017-12-01");
        spot.printSpot();
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Get the historical EUR/USD rates
    Quote *eurusd = new Quote("EURUSD=X");
    eurusd->getHistoricalSpots("2018-01-01", "2018-01-10", "1d");
    eurusd->printSpots();
    */
    // Free memory
    delete snp500;
    //delete eurusd;
}