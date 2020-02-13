#include "Client.hpp"


Client::Client()
{
}

Client::~Client()
{
}


void Client::establishPort(bool create)
{
}

//Client
RESPONSE_STATUS Client::searchConection() 
{
    socket.unbind();
    if (socket.bind(8007) != sf::Socket::Done)
    {
        return RESPONSE_STATUS::NONE_RESPONSE;
    }

    sf::Packet packetSend;
    packetSend << REQUEST_STATUS::SEARCH_CONNECTION;
    socket.setBlocking(true);


    if (socket.send(packetSend, sf::IpAddress::Broadcast, 7008) != sf::Socket::Done) {
        return RESPONSE_STATUS::NONE_RESPONSE;
        
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

            sf::IpAddress address = sender;
            ipReceiver = address;

            return RESPONSE_STATUS::ESTABLISHED_CONNECTION;
            if(response == RESPONSE_STATUS::CONNECTION_AVAILABLE) {
                
            }
        }
        elapsedSeconds = std::chrono::system_clock::now() - start;
    } while(elapsedSeconds.count() <= MAX_LISTEN_TIME);

    return RESPONSE_STATUS::NONE_RESPONSE;
}

RESPONSE_STATUS Client::listenConection()
{
    socket.unbind();
    if (socket.bind(7008) != sf::Socket::Done)
    {
        return RESPONSE_STATUS::NONE_RESPONSE;
    }
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
        
            ipReceiver = address;
        
            if (socket.send(packetSend, sender, 8007) != sf::Socket::Done)
            {
                std::cout << "Send error" << std::endl;
            }
            return RESPONSE_STATUS::ESTABLISHED_CONNECTION;
            
        }

        elapsedSeconds = std::chrono::system_clock::now() - start;
    } while(elapsedSeconds.count() <= MAX_LISTEN_TIME);
    return RESPONSE_STATUS::NONE_RESPONSE;
}

void Client::setReceiver(sf::IpAddress sc) 
{
    ipReceiver = sc;
}

sf::IpAddress Client::getReceiver()
{
    return ipReceiver;
}