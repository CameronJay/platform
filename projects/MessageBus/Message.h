#ifndef MessageBus_Message
#define MessageBus_Message

#include <string>

class Message
{
public:
    Message();
    virtual ~Message();

private:
    std::string text;
    
};

#endif // !MessageBus_Message