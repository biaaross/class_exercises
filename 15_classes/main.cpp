#include <iostream>
#include "portfolio.h"
#include "stock.h"
#include "crypto.h"

int main() {
    Portfolio<Asset> myPortfolio(2); 

    myPortfolio.addAsset(new Stock("Apple", 0.0, "USD", 10, 150.5));
    myPortfolio.addAsset(new Crypto("Bitcoin", 0.0, "USD", 0.5, 63000.0));
    myPortfolio.addAsset(new Stock("Tesla", 0.0, "USD", 5, 175.0)); 

    std::cout << "------------------------------------" << std::endl;
    std::cout << "Total Net Worth: " << myPortfolio.totalNetWorth() << " USD" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    myPortfolio.saveToFile("portfolio_data.txt");
  
    return 0;
}