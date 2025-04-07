// main.cpp
#include "Desserts/DessertFactory.h"

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

int main()
{
    // Struct to define WebSocket behavior (must be well-formed)
    struct PerSocketData
    {
    };

    uWS::App()
        .ws<PerSocketData>("/*", {.open = [](auto *ws)
                                  { std::cout << "A client connected!" << std::endl; },
                                  .message = [](auto *ws, std::string_view message, uWS::OpCode opCode)
                                  {
                                      std::cout << "Received: " << message << std::endl;
                                      ws->send(message, opCode); // Echo back
                                  },
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