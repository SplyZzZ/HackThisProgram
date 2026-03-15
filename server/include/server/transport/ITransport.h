#pragma once
#include <functional>
#include <string>

 namespace server::transport {
  class ITransport {
  public:
   virtual void asyncWrite(const std::string& data, std::function<void()> handler) = 0;
   virtual void asyncRead(const std::function<void(const std::string&)>& handler) = 0;
   virtual ~ITransport() = default;
  };
 }
