//
// Created by itsl on 18-3-9.
//

#ifndef LIGHTRO_1_0_SERVER_TCP_SOCKET_HPP
#define LIGHTRO_1_0_SERVER_TCP_SOCKET_HPP

#include "socket.hpp"

#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::tcp;

namespace ltrov{
namespace network{

class TcpSocket: public Socket<tcp::socket> {

protected:

public:
    explicit TcpSocket(tcp::socket** socket);

    void asyncWrite(std::string data) override;

    void asyncWriteCallBack(std::size_t bytesTransed,
                            const boost::system::error_code& error);

    std::size_t write(std::string data) override;
};

}
}

#endif //LIGHTRO_1_0_SERVER_TCP_SOCKET_HPP
