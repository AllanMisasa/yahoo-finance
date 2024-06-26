#include "quote.hpp"
#include <iostream>
#include <vector>
#include <cstdint>

#include <mongocxx/client.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

int main() {
    // sudo /sbin/ldconfig -v was needed to update shared object links
    mongocxx::instance instance{};
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);

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
    */
    // Get the historical EUR/USD rates
    Quote *eurusd = new Quote("GBPDKK=X");
    eurusd->getHistoricalSpots("2024-05-01", "2024-05-07", "1d");
    eurusd->printSpots();
    
    // Free memory
    delete snp500;
    delete eurusd;
}