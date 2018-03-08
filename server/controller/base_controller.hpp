//
// Created by itsl on 18-3-8.
//

#ifndef LIGHTRO_1_0_SERVER_CONTROLLER_HPP
#define LIGHTRO_1_0_SERVER_CONTROLLER_HPP


#include <string>

#include <boost/asio.hpp>

namespace ltrov{
namespace controller{

class BaseController {
protected:
    unsigned int event;

public:
    /**
     * Construct function
     */
    BaseController();

    /**
     * virtual destruct function
     */
    virtual ~BaseController();

    /**
     * 获取 eventid
     * @return eventId
     */
    virtual unsigned int getEventId();

    /**
     * 事件处理
     * @param data
     */
    virtual void handler(std::string data,
                         boost::asio::ip::tcp::socket** sock) = 0;


};  // class BaseController

}   // namespace ltrov
}   // namespace controller"


#endif //LIGHTRO_1_0_SERVER_CONTROLLER_HPP
