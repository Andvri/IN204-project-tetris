#ifndef CLIENT_CLASS
#define CLIENT_CLASS

#include "NetworkConstants.hpp"
#include <chrono>
#include <iostream>


#include <SFML/Network.hpp>
class Client
{
private:
    sf::IpAddress ipReceiver;
    sf::UdpSocket socket;
public:
    Client();
    ~Client();

    RESPONSE_STATUS searchConection();
    RESPONSE_STATUS listenConection();

    sf::IpAddress getReceiver();
    void setReceiver(sf::IpAddress ia);
    void establishPort(bool create);
};


#endif