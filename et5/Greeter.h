#ifndef GREETER_H
#define GREETER_H


class Greeter
{
    public:
        Greeter();
        virtual ~Greeter()=default;
        virtual std::string Say() const =0;
        virtual void print() const =0;
};

#endif // GREETER_H
