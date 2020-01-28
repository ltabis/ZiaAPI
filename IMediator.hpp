
#pragma once

#include "Data.hpp"
#include "IModule.hpp"

namespace Zia
{

	/// \class IModule
	/// \brief An interface the mediator, the core of the application server.
	class IMediator
	{
	public:

		virtual void notify(IModule *sender, Data &data) = 0;
	};
}