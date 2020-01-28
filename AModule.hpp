
#pragma once

#include "IModule.hpp"

namespace Zia
{

	/// \class AModule
	/// \brief An abstract class wich inherits from the IModule interface.
	class AModule : public IModule
	{
	public:

		AModule(IMediator *mediator, const std::string &name = "unknown", std::size_t priority = 0) : _mediator(mediator), _name(name), _priority(priority) {}

		/// \brief get the name of the current module.
		/// \return the name of the module.
		inline std::string name() const override
		{
			return _name;
		}
	
		/// \brief get the priority of the current module.
		/// \return the priority of the module.
		inline std::size_t priority() const override
		{
			return _priority;
		}

		/// \brief get the status of the module.
		/// \return status of the module.
		inline ModuleStatus status() const override
		{
			return _status;
		}

	protected:

		/* String containing the name of the module. */
		std::string _name;

		/* Enum of the current status of the module. */
		ModuleStatus _status;

		/* priority number of the current module. */
		std::size_t _priority;

		/* Reference to the mediator class */
		IMediator *_mediator;
	};
}