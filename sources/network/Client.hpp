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
};

Client::Client()
{
    if (socket.bind(PORTS::RECIVE) != sf::Socket::Done)
    {
        return;
    }
}

Client::~Client()
{
}

RESPONSE_STATUS Client::searchConection() 
{
    sf::Packet packetSend;
    packetSend << REQUEST_STATUS::SEARCH_CONNECTION;
    socket.setBlocking(true);

    if (socket.send(packetSend, sf::IpAddress::Broadcast, PORTS::SEND) != sf::Socket::Done) {
        return;
    }

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds;

    socket.setBlocking(false);

    do {
        sf::Packet packetRecv;
        sf::IpAddress sender;
        unsigned short port;
        
        if (socket.receive(packetRecv, sender, port) == sf::Socket::Done) {
            sf::Uint32 datatypeValue;

            packetRecv >> datatypeValue;
            RESPONSE_STATUS response = static_cast<RESPONSE_STATUS>(datatypeValue);

            if(response == RESPONSE_STATUS::CONNECTION_AVAILABLE) {
                
                    sf::IpAddress address = sender;

                    std::cout << "Server: " << address << std::endl;
            }
        }
        elapsedSeconds = std::chrono::system_clock::now() - start;
    } while(elapsedSeconds.count() <= MAX_SEARCH_TIME);
}

RESPONSE_STATUS Client::listenConection()
{

    socket.setBlocking(false);
    

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds;
    do {
        sf::Packet packetRecv;
        sf::IpAddress sender;
        unsigned short port;

        if (socket.receive(packetRecv, sender, port) == sf::Socket::Done)
        {
            sf::Packet packetSend;
            sf::IpAddress address = sender;
            packetSend << RESPONSE_STATUS::CONNECTION_AVAILABLE;

            std::cout << "Client:" << address << std::endl;
            if (socket.send(packetSend, sender, PORTS::SEND) != sf::Socket::Done)
                std::cout << "Send error" << std::endl;
        }


    } while(elapsedSeconds.count() <= MAX_LISTEN_TIME);
    return RESPONSE_STATUS::NONE;
}

void Client::setReceiver(sf::IpAddress sc) 
{
    ipReceiver = sc;
}

sf::IpAddress Client::getReceiver()
{
    return ipReceiver;
}

#endif