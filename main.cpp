// main.cpp
#include "Desserts/DessertFactory.h"
#include "Transaction.h"

// int main()
// {
//     DessertFactory factory;
//     factory.createDessert("cake")->serve();
//     factory.createDessert("brownie")->serve();
//     return 0;
// }

#include <uwebsockets/App.h>
// #include <uWS/App.h>
#include <iostream>
// #include <memory> // for std::unique_ptr
#include <boost/algorithm/string.hpp>
// #include <vector>
// #include <string>

int main()
{
    DessertFactory factory;
    // factory.createDessert("cake")->serve();
    // factory.createDessert("brownie")->serve();

    std::map<std::string, int> sales = {
        {"cake", 0},
        {"brownie", 0},
    };

    std::vector<std::unique_ptr<Transaction>> transactions;

    // Struct to define WebSocket behavior (must be well-formed)
    struct PerSocketData
    {
    };

    uWS::App()
        .ws<PerSocketData>("/*", {.open = [](auto *ws)
                                  { std::cout << "A client connected!" << std::endl; },
                                  .message = [&transactions, &factory, &sales](auto *ws, std::string_view message, uWS::OpCode opCode)
                                  {
                                      std::cout << "Received: " << message << std::endl;
                                      std::string str(message);
                                      std::cout << str << std::endl;
                                      std::vector<std::string> results;

                                      boost::split(results, str, boost::is_any_of(" "));
                                      for (std::string word : results)
                                      {
                                          std::cout << word << std::endl;
                                      }

                                      if (results.size() != 3)
                                      {
                                          std::cout << "Invalid input" << std::endl;
                                          ws->send("Invalid input", opCode);
                                      }
                                      else
                                      {
                                        int num;
                                        std::string symbol = results[1];
                                        std::string quantity = results[2];

                                        bool error = false;
                                    
                                        if (symbol != "cake" && symbol != "brownie") {
                                            std::cout << "Invalid symbol. Available symbols: cake, brownie." << std::endl; 
                                        }

                                        try {
                                        num = std::stoi(quantity);
                                        std::cout << "The integer value is: " << num << std::endl;
                                        } catch (const std::invalid_argument& e) {
                                        std::cerr << "Invalid argument: " << e.what() << std::endl;
                                        } catch (const std::out_of_range& e) {
                                        std::cerr << "Out of range: " << e.what() << std::endl;
                                        }
                                        if (!error){
                                            sales[symbol] += num;
                                            std::unique_ptr<Transaction> temp = std::make_unique<Transaction>(
                                                200,
                                                factory.createDessert(results[1]));
                                            std::cout << "Transaction ID: " << temp->orders << std::endl;
    
                                            transactions.push_back(std::move(temp));
                                            ws->send(message, opCode); // Echo back
                                        } else 
                                        {
                                            ws->send("Invalid input", opCode);
                                        }
                                        
                                      } },
                                  .close = [](auto *ws, int code, std::string_view msg)
                                  { std::cout << "Connection closed: " << msg << std::endl; }})
        .listen(9001, [](auto *listen_socket)
                {
            if (listen_socket) {
                std::cout << "Listening on port 9001" << std::endl;
            } else {
                std::cerr << "Failed to listen" << std::endl;
            } })
        .run();

    return 0;
}