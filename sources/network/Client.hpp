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
    int           portSend;
    int           portRecv;
    sf::UdpSocket socket;
public:
    Client();
    ~Client();

    RESPONSE_STATUS searchConection();
    RESPONSE_STATUS listenConection();

    sf::IpAddress getReceiver();
    void setReceiver(sf::IpAddress ia);
    void establishPort(bool create);

    void recvData(std::vector<int> &v);
    void sendData(std::vector<int> v);
};


#endif