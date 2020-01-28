/**
 *  @file     IMediator.hpp
 *  @author   tabis
 *  @date     2020-01-28
 * 
 *  project: zia
 * 
 */

#pragma once

#include "Data.hpp"
#include "IModule.hpp"

namespace Zia
{

	/// @class IMediator
	/// @brief An interface for the mediator, the core of the application server. It will be passed to all modules.
	class IMediator
	{
	public:

		/** 
		 * @brief notify the mediator that the sender has finished processing data.
		 * @param sender : the module that has called notify.
		 * @param data : the data processed by the sender.
		 */
		virtual void notify(IModule *sender, Data &data) = 0;
	};
}