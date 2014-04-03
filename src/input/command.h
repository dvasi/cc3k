#ifndef __COMMAND_H__
#define __COMMAND_H__

class Command{

protected:
    int x, y;
public:
    Command(int x, int y);
    virtual int getXPos();
    virtual int getYPos();
    virtual ~Command() = 0;
};
#endif
