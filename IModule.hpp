/**
 *  @file     IModule.hpp
 *  @author   tabis
 *  @date     2020-01-28
 * 
 *  project: zia
 * 
 */

#pragma once

#include "Data.hpp"

// Forward declaration of the mediator interface.
namespace Zia
{
	class IMediator;
}

/// @namespace Zia
/// @brief The Zia web server namespace.
namespace Zia
{
	/// @enum ModuleStatus
	/// @brief enum with all status possible for a module.
	enum ModuleStatus
	{
		Done, Error, Processing
	};

	/// @class IModule
	/// @brief An interface for modules, wich is the API designed to interact with the Application server.
	class IModule
	{
	public:

		/** 
		 * @brief destructor.
		 */
		virtual ~IModule() = default;

		/** 
		 * @brief get the name of the current module.
		 * @return the name of the module.
		 */
		virtual std::string name() const = 0;
	
		/** 
		 * @brief get the priority of the current module.
		 * @return the priority of the module.
		 */
		virtual std::size_t priority() const = 0;
	
		/** 
		 * @brief get the current status of the module.
		 * @return status of the module.
		 */
		virtual ModuleStatus status() const = 0;

		/** 
		 * @brief unloads the current module.
		 */
		virtual void unloadModule() = 0;
	
		/** 
		 * @brief loads the current module.
		 * @param priority : order priority of the module. 
		 */
		virtual void loadModule(std::size_t priority) = 0;
	
		/** 
		 * @brief set the priority of the current module.
		 * @param priority : the priority to assign to current the module.
		 */
		virtual void setPriority(std::size_t priority) = 0;

		/** 
		 * @brief process the data.
		 * @param data : structure with informations about the resquest and the response.
		 */
		virtual void processData(Data &data) = 0;
	};
}