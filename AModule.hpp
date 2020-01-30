/**
 *  @file     AModule.hpp
 *  @author   tabis
 *  @date     2020-01-28
 * 
 *  project: zia
 * 
 */

#pragma once

#include "IModule.hpp"

namespace Zia
{

	/// @class AModule
	/// @brief An abstract class wich inherits from the IModule interface.
	class AModule : public IModule
	{
	public:

		/** 
		 * @brief Module constructor.
		 * @param mediator : a reference to the mediator of the server.
		 * @param name : the name of the module (default: "unknown").
		 * @param priority : the priority of the module (default: 0).
		 */
		AModule(IMediator *mediator, const std::string &name = "unknown", std::size_t priority = 0) : _mediator(mediator), _name(name), _priority(priority), _time_since_processing(std::chrono::high_resolution_clock::now()) {}

		/** 
		 * @brief get the name of the current module.
		 * @return the name of the module.
		 */
		inline std::string name() const override
		{
			return _name;
		}
	
		/** 
		 * @brief get the priority of the current module.
		 * @return the priority of the module.
		 */
		inline std::size_t priority() const override
		{
			return _priority;
		}

		/** 
		 * @brief get the status of the module.
		 * @return status of the module.
		 */
		inline ModuleStatus status() const override
		{
			return _status;
		}

		/** 
		 * @brief Get the time spent processing data.
		 * if the module isn't processing any data, it should return 0.
		 * The server can verify if it needs to kill the module or not.
		 * @return processing time in milliseconds.
		 */
		std::chrono::milliseconds processTime() const
		{
			return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _time_since_processing);
		}

		/** 
		 * @brief set the configuration file needed by the module.
		 * @param config_file_path : file to be loaded by the module when it needs additional configuration.
		 */
		inline void setConfig(const std::string &config_file_path) override
		{
			_config_file_path = config_file_path;
		}

	protected:

		/* String containing the name of the module. */
		std::string _name;

		/* Enum of the current status of the module. */
		ModuleStatus _status;

		/* Priority number of the current module. */
		std::size_t _priority;

		/* Reference to the mediator class */
		IMediator *_mediator;

		/* set when the module start processing data, used by the mediator to check if the module needs to be shut down. */
		std::chrono::high_resolution_clock::time_point _time_since_processing;

		/* An eventual configuration file needed by the module. */
		std::string _config_file_path;
	};
}