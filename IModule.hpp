/**
 *  @file     IModule.hpp
 *  @author   tabis
 *  @date     2020-01-28
 * 
 *  project: zia
 * 
 */

#pragma once

#include <chrono>

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

		/** 
		 * @brief Get the time spent processing data.
		 * if the module isn't processing any data, it should return 0.
		 * The server can verify if it needs to kill the module or not.
		 * @return processing time in milliseconds.
		 */
		virtual std::chrono::milliseconds processTime() const = 0;

		/** 
		 * @brief set the configuration file needed by the module.
		 * @param config_file_path : file to be loaded by the module when it needs additional configuration.
		 */
		virtual void setConfig(const std::string &config_file_path) = 0;

		/** 
		 * @brief reloads the configuration file of the current module.
		 */
		virtual void reloadConfig() = 0;
	};
}