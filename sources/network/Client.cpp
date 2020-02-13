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
    if (socket.bind(8007) != sf::Socket::Done)
    {
        return RESPONSE_STATUS::NONE_RESPONSE;
    }
    std::cout << "Init search conection" << std::endl;
    sf::Packet packetSend;
    packetSend << REQUEST_STATUS::SEARCH_CONNECTION;
    socket.setBlocking(true);

    std::cout << "Start send package broadcast" << std::endl;
    if (socket.send(packetSend, sf::IpAddress::Broadcast, 7008) != sf::Socket::Done) {
        std::cout << "NONE_RESPONSE" << std::endl;
        return RESPONSE_STATUS::NONE_RESPONSE;
        
    }
    std::cout << "End send package broadcast" << std::endl;

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds;

    socket.setBlocking(false);

    do {
        sf::Packet packetRecv;
        sf::IpAddress sender;
        unsigned short port;
        std::cout << "DO SEARCH: " << socket.getLocalPort() << std::endl;
        if (socket.receive(packetRecv, sender, port) == sf::Socket::Done) {
            sf::Uint32 datatypeValue;
            std::cout << "Reception Package" << std::endl;
            packetRecv >> datatypeValue;
            RESPONSE_STATUS response = static_cast<RESPONSE_STATUS>(datatypeValue);

            sf::IpAddress address = sender;

            std::cout << "Server: " << address << std::endl;
            return RESPONSE_STATUS::ESTABLISHED_CONNECTION;
            if(response == RESPONSE_STATUS::CONNECTION_AVAILABLE) {
                
            }
        }
        elapsedSeconds = std::chrono::system_clock::now() - start;
    } while(elapsedSeconds.count() <= MAX_LISTEN_TIME);
    std::cout << "NONE_RESPONSE" << std::endl;
    return RESPONSE_STATUS::NONE_RESPONSE;
}

RESPONSE_STATUS Client::listenConection()
{

    if (socket.bind(7008) != sf::Socket::Done)
    {
        return RESPONSE_STATUS::NONE_RESPONSE;
    }
    socket.setBlocking(false);
    std::cout << "Start listen" << std::endl;

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds;
    do {
        sf::Packet packetRecv;
        sf::IpAddress sender;
        unsigned short port;

        std::cout << "DO LISTEN: " << socket.getLocalPort()<< std::endl;
        if (socket.receive(packetRecv, sender, port) == sf::Socket::Done)
        {
            sf::Packet packetSend;
            sf::IpAddress address = sender;
            packetSend << RESPONSE_STATUS::CONNECTION_AVAILABLE;
            std::cout << "Reception Package" << std::endl;

            std::cout << "Client:" << address << std::endl;
            if (socket.send(packetSend, sender, 8007) != sf::Socket::Done)
            {
                std::cout << "Send error" << std::endl;
            }
            return RESPONSE_STATUS::ESTABLISHED_CONNECTION;
            
        }

        elapsedSeconds = std::chrono::system_clock::now() - start;
    } while(elapsedSeconds.count() <= MAX_LISTEN_TIME);
    std::cout << "NONE_RESPONSE" << std::endl;
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