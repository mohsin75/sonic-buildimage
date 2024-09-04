
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__rebootbackend_gnoi_container_shutdown_dbus_h__PROXY_MARSHAL_H
#define __dbusxx__rebootbackend_gnoi_container_shutdown_dbus_h__PROXY_MARSHAL_H

#include <dbus-c++/dbus.h>
#include <cassert>

namespace org {
namespace SONiC {
namespace HostService {

class gnoi_container_shutdown_proxy
: public ::DBus::InterfaceProxy
{
public:

    gnoi_container_shutdown_proxy()
    : ::DBus::InterfaceProxy("org.SONiC.HostService.gnoi_container_shutdown")
    {
    }

public:

    /* properties exported by this interface */
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    void stop_container(const std::vector< std::string >& options, int32_t& argout0, std::string& argout1)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << options;
        call.member("stop_container");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> argout0;
        ri >> argout1;
    }

    void stop_container_status(const std::vector< std::string >& options, int32_t& argout0, std::string& argout1)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << options;
        call.member("stop_container_status");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ri >> argout0;
        ri >> argout1;
    }


public:

    /* signal handlers for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
};

} } } 
#endif //__dbusxx__rebootbackend_gnoi_container_shutdown_dbus_h__PROXY_MARSHAL_H
