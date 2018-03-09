//
// Created by itsl on 18-3-9.
//

#ifndef LIGHTRO_1_0_SERVER_SOCKET_HPP
#define LIGHTRO_1_0_SERVER_SOCKET_HPP

#include <string>

#include <boost/asio.hpp>

namespace ltrov{
namespace network{

template <typename SOCK_TYPE>
class Socket {
protected:
    SOCK_TYPE** socket;

public:
    explicit Socket(SOCK_TYPE** socket);

    /**
     * async write
     *
     * @param data
     */
    virtual void asyncWrite(std::string data) = 0;

    /**
     * sync write
     * @param data
     * @return
     */
    virtual std::size_t write(std::string data) = 0;
};

}   // namespace ltrov
}   // namespace network

#endif //LIGHTRO_1_0_SERVER_SOCKET_HPP
