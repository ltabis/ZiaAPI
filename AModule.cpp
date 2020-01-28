#include "AModule.hpp"

std::string Zia::AModule::name() const
{
	return _name;
}

std::size_t Zia::AModule::priority() const
{
	return _priority;
}

Zia::ModuleStatus Zia::AModule::status() const
{
	return _status;
}