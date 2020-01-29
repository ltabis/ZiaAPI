
#include <iostream>
#include "Data.hpp"
#include "AModule.hpp"
#include "IMediator.hpp"

class Module : public Zia::AModule
{
    public:
        Module(Zia::IMediator *mediator, const std::string &name = "unknown", std::size_t priority = 0) : AModule(mediator, name, priority) {}

        void unloadModule() override
        {
            std::cout << "module unloaded." << std::endl;
        }
	
	void loadModule(std::size_t priority) override
        {
            (void) priority;
        }
	
	inline void setPriority(std::size_t priority) override
        {
            _priority = priority;
        }

	void processData(Zia::Data &data) override
        {
            _mediator->notify(this, data);
        }
};

class Mediator : public Zia::IMediator
{
    void notify(Zia::IModule *sender, Zia::Data &data) override
    {
        (void) data;

        std::cout << "Hey! Mediator here. " << sender->name() << " sent me data!" << std::endl;
    }
};

int main()
{
    Mediator mediator;
    Module m(&mediator, "Module", 1);
    Zia::Data data;

    m.loadModule(1);
    m.processData(data);

    return 0;
}
