#ifndef GREETER_H
#define GREETER_H
#include <functional>
#include <memory>

class Greeter
{
    public:

        virtual std::string Say() const =0;
        virtual void print() const =0;
        virtual Greeter* clone() const=0;
        std::function<std::string(std::shared_ptr<Greeter>)> display = [](std::shared_ptr<Greeter> greet) {
            //std::cout << "This is std::function call." << std::endl;
            return greet->Say();
            };
};

class HelloGreeter : public Greeter{
public:
    HelloGreeter();
    std::string Say()const override;
    void print() const override;
    Greeter* clone() const override;
    HelloGreeter(const HelloGreeter&);
};





class MoroGreeter: public Greeter{

    public:
        MoroGreeter();
        MoroGreeter(Greeter&);
        std::string Say()const override;
        void print()const override;
        Greeter* clone() const override;
        MoroGreeter(const MoroGreeter&);
    };



#endif // GREETER_H
